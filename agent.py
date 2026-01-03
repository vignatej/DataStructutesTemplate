#!/usr/bin/env python3
"""
agent.py

Agent that connects to a Spring backend WebSocket and:
 - registers itself
 - proxies HTTP requests to local Jupyter
 - opens local websocket connections to Jupyter for kernel channels and tunnels frames

Usage:
    export BACKEND_WS="ws://<backend-host>:8080/agent-ws"
    export AGENT_ID="my-machine-1"
    export JUPYTER_PORT=8888
    export WORKSPACE="."
    python agent.py
"""

import os
import json
import base64
import threading
import time
import uuid
import traceback
from urllib.parse import quote, unquote

import requests
import websocket  # websocket-client

# Configuration (can be overridden via env vars)
BACKEND_WS = os.environ.get("BACKEND_WS", "ws://localhost:8080/agent-ws")
AGENT_ID = os.environ.get("AGENT_ID", f"agent-{uuid.uuid4().hex[:8]}")
JUPYTER_PORT = int(os.environ.get("JUPYTER_PORT", "8888"))
WORKSPACE = os.environ.get("WORKSPACE", ".")

# Globals
ws_backend_app = None        # WebSocketApp instance to backend
ws_backend_lock = threading.Lock()
running = True

# bridgeId -> LocalBridge
local_bridges = {}
local_bridges_lock = threading.Lock()

# small helper: list notebooks in workspace (non-recursive optional -> here recursive)
def list_notebooks():
    notebooks = []
    for root, dirs, files in os.walk(WORKSPACE):
        for f in files:
            if f.endswith(".ipynb"):
                # send relative path
                rel = os.path.relpath(os.path.join(root, f), WORKSPACE)
                notebooks.append(rel.replace("\\", "/"))
    return notebooks

# Helper to send JSON message to backend (thread-safe)
def send_to_backend(msg: dict):
    global ws_backend_app
    try:
        text = json.dumps(msg)
        with ws_backend_lock:
            if ws_backend_app and ws_backend_app.sock and ws_backend_app.sock.connected:
                ws_backend_app.send(text)
            else:
                print("Backend not connected; cannot send message:", msg.get("type"))
    except Exception:
        print("Error sending to backend:", traceback.format_exc())

# Handle proxy-request: forward to local Jupyter HTTP and respond with proxy-response
def handle_proxy_request(m: dict):
    try:
        requestId = m.get("requestId")
        path = m.get("path", "")
        method = m.get("method", "GET")
        headers = m.get("headers", {}) or {}
        body_b64 = m.get("body", "") or ""
        body = base64.b64decode(body_b64) if body_b64 else None

        # build URL to local jupyter
        # ensure path doesn't start with a leading slash twice
        if path.startswith("/"):
            path = path[1:]
        url = f"http://127.0.0.1:{JUPYTER_PORT}/{path}"

        # remove 'Host' header if present (requests will set it)
        headers.pop("host", None)
        headers.pop("Host", None)

        # Make the request to local Jupyter
        r = requests.request(method, url, headers=headers, data=body, stream=True, timeout=30)

        # read body
        resp_body = r.content
        b64 = base64.b64encode(resp_body).decode()

        # copy headers (as simple dict)
        resp_headers = dict(r.headers)

        resp = {
            "type": "proxy-response",
            "requestId": requestId,
            "agentId": AGENT_ID,
            "status": r.status_code,
            "headers": resp_headers,
            "body": b64
        }
        send_to_backend(resp)
    except Exception as e:
        print("Error handling proxy-request:", e)
        resp = {
            "type": "proxy-response",
            "requestId": m.get("requestId"),
            "agentId": AGENT_ID,
            "status": 502,
            "headers": {},
            "body": base64.b64encode(str(e).encode()).decode()
        }
        send_to_backend(resp)

# LocalBridge object holds the local websocket to Jupyter for a bridgeId
class LocalBridge:
    def __init__(self, bridge_id: str, jupyter_path: str, backend_send_fn):
        self.bridge_id = bridge_id
        self.jupyter_path = jupyter_path  # e.g., "api/kernels/<id>/channels?session=..."
        self.backend_send_fn = backend_send_fn
        self.ws = None
        self.thread = None
        self.alive = False

    def start(self):
        self.thread = threading.Thread(target=self._run, daemon=True)
        self.thread.start()

    def _run(self):
        # try to open local websocket to jupyter
        try:
            # ensure path is URL-encoded properly (but preserve query)
            # if path has query, ws URL is ws://127.0.0.1:port/<path>
            url_path = self.jupyter_path
            if url_path.startswith("/"):
                url_path = url_path[1:]
            jurl = f"ws://127.0.0.1:{JUPYTER_PORT}/{url_path}"

            # create websocket connection (synchronous)
            self.ws = websocket.create_connection(jurl, timeout=30)
            self.alive = True
            # notify backend that ws opened
            self.backend_send_fn({
                "type": "ws-opened",
                "bridgeId": self.bridge_id,
                "agentId": AGENT_ID
            })
            print(f"[bridge {self.bridge_id}] connected to local jupyter websocket: {jurl}")

            # read loop
            while self.alive:
                try:
                    data = self.ws.recv()
                    if data is None:
                        break
                    # websocket-client returns str for text frames, bytes for binary
                    opcode = "text" if isinstance(data, str) else "binary"
                    raw_bytes = data.encode() if isinstance(data, str) else data
                    b64 = base64.b64encode(raw_bytes).decode()
                    out = {
                        "type": "ws-frame",
                        "bridgeId": self.bridge_id,
                        "opcode": opcode,
                        "data": b64,
                        "agentId": AGENT_ID
                    }
                    self.backend_send_fn(out)
                except websocket.WebSocketTimeoutException:
                    continue
                except Exception as e:
                    # pipe error and break
                    print(f"[bridge {self.bridge_id}] local ws read error:", e)
                    break
        except Exception as e:
            print(f"[bridge {self.bridge_id}] failed to open local websocket: {e}")
            self.backend_send_fn({
                "type": "ws-failed",
                "bridgeId": self.bridge_id,
                "agentId": AGENT_ID,
                "error": str(e)
            })
        finally:
            self.alive = False
            try:
                if self.ws:
                    self.ws.close()
            except:
                pass
            self.backend_send_fn({
                "type": "ws-closed",
                "bridgeId": self.bridge_id,
                "agentId": AGENT_ID
            })
            print(f"[bridge {self.bridge_id}] closed")

    def send_frame(self, opcode: str, raw_bytes: bytes):
        try:
            if not self.ws:
                print(f"[bridge {self.bridge_id}] no ws to send")
                return
            if opcode == "text":
                self.ws.send(raw_bytes.decode())
            else:
                self.ws.send(raw_bytes, opcode=websocket.ABNF.OPCODE_BINARY)
        except Exception as e:
            print(f"[bridge {self.bridge_id}] error sending frame:", e)

    def close(self):
        self.alive = False
        try:
            if self.ws:
                self.ws.close()
        except:
            pass

# Handle incoming messages from backend
def on_backend_message(ws, message):
    try:
        m = json.loads(message)
    except Exception:
        print("Non-json message from backend:", message)
        return

    t = m.get("type")
    if t == "proxy-request":
        threading.Thread(target=handle_proxy_request, args=(m,), daemon=True).start()
        return

    if t == "ws-open":
        bridgeId = m.get("bridgeId")
        path = m.get("path", "")
        print(f"Got ws-open for bridge {bridgeId} path={path}")
        # create LocalBridge and start it
        lb = LocalBridge(bridgeId, path, send_to_backend)
        with local_bridges_lock:
            local_bridges[bridgeId] = lb
        lb.start()
        return

    if t == "ws-frame":
        bridgeId = m.get("bridgeId")
        opcode = m.get("opcode", "binary")
        data_b64 = m.get("data", "")
        try:
            raw = base64.b64decode(data_b64) if data_b64 else b""
        except Exception:
            raw = b""
        with local_bridges_lock:
            lb = local_bridges.get(bridgeId)
        if lb:
            lb.send_frame(opcode, raw)
        else:
            print(f"ws-frame for unknown bridge {bridgeId}")
        return

    if t == "ws-close":
        bridgeId = m.get("bridgeId")
        with local_bridges_lock:
            lb = local_bridges.pop(bridgeId, None)
        if lb:
            lb.close()
        return

    if t == "register-result":
        # optional handling
        print("Register ack/result:", m)
        return

    # unknown message
    print("Unhandled backend message type:", t)

def on_backend_open(ws):
    print("Connected to backend websocket at", BACKEND_WS)
    # send register message
    reg = {
        "type": "register",
        "agentId": AGENT_ID,
        "jupyterPort": JUPYTER_PORT,
        "workspaceDir": WORKSPACE,
        "files": list_notebooks()
    }
    send_to_backend(reg)

def on_backend_close(ws, close_status_code, close_msg):
    print("Backend websocket closed:", close_status_code, close_msg)

def on_backend_error(ws, error):
    print("Backend websocket error:", error)

# Start the backend WebSocketApp and keep it running / reconnecting
def run_backend_ws_loop():
    global ws_backend_app
    while running:
        try:
            ws_backend_app = websocket.WebSocketApp(
                BACKEND_WS,
                on_open=lambda ws: on_backend_open(ws),
                on_message=lambda ws, msg: on_backend_message(ws, msg),
                on_close=lambda ws, code, msg: on_backend_close(ws, code, msg),
                on_error=lambda ws, err: on_backend_error(ws, err)
            )
            # use run_forever which blocks until connection is closed
            ws_backend_app.run_forever(ping_interval=20, ping_timeout=10)
        except Exception as e:
            print("Backend WS run_forever exception:", e)
        print("Reconnecting to backend in 3s...")
        time.sleep(3)

if __name__ == "__main__":
    print("Agent starting with:")
    print("  BACKEND_WS =", BACKEND_WS)
    print("  AGENT_ID   =", AGENT_ID)
    print("  JUPYTER_PORT =", JUPYTER_PORT)
    print("  WORKSPACE  =", WORKSPACE)
    try:
        run_backend_ws_loop()
    except KeyboardInterrupt:
        print("Agent interrupted, shutting down")
    finally:
        running = False
        # close local bridges
        with local_bridges_lock:
            for b in list(local_bridges.values()):
                try:
                    b.close()
                except:
                    pass
        if ws_backend_app:
            try:
                ws_backend_app.close()
            except:
                pass

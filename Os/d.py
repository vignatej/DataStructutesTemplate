import multiprocessing

def worker(conn):
    msg = conn.recv()      # receive from parent
    print(f"Child got: {msg}")
    conn.send(f"{msg} processed")  # send back
    conn.close()

if __name__ == "__main__":
    parent_conn, child_conn = multiprocessing.Pipe()

    p = multiprocessing.Process(target=worker, args=(child_conn,))
    p.start()

    parent_conn.send("Hello from parent")  # send to child
    print("Parent got:", parent_conn.recv())  # receive from child

    p.join()

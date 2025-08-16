import threading
import time

v=0
def inc():
    global v
    for i in range(1000):
        v+=i

threads = []
for i in range(100):
    t = threading.Thread(target=inc)
    threads.append(t)
    t.start()

time.sleep(5)

for i in threads:
    i.join()

print(v)

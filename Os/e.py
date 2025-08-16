import multiprocessing
import time, random

def worker(q, name):
    time.sleep(random.uniform(0.5, 2))
    q.put(f"Result from {name}")

if __name__ == "__main__":
    q = multiprocessing.Queue()
    processes = []

    for i in range(5):
        p = multiprocessing.Process(target=worker, args=(q, f"Worker-{i}"))
        processes.append(p)
        p.start()

    for p in processes:
        p.join()

    while not q.empty():
        print(q.get())

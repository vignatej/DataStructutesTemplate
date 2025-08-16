# Dining philosophers
import multiprocessing
import time

NUM_PHILOSOPHERS = 5

def philosopher(i, left, right, sem):
    while True:
        print(f"Philosopher {i} is thinking")
        time.sleep(1)

        sem.acquire()   # ✅ limit concurrency

        left.acquire()
        print(f"Philosopher {i} picked up left fork")

        right.acquire()
        print(f"Philosopher {i} picked up right fork and is eating")
        time.sleep(1)

        right.release()
        left.release()
        sem.release()
        print(f"Philosopher {i} put down forks")

if __name__ == "__main__":
    with multiprocessing.Manager() as manager:
        forks = [manager.Lock() for _ in range(NUM_PHILOSOPHERS)]
        sem = manager.Semaphore(NUM_PHILOSOPHERS - 1)

        processes = []
        for i in range(NUM_PHILOSOPHERS):
            p = multiprocessing.Process(
                target=philosopher,
                args=(i, forks[i], forks[(i+1) % NUM_PHILOSOPHERS], sem)
            )
            processes.append(p)
            p.start()

        for p in processes:
            p.join()

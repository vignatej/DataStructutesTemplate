import multiprocessing, time, random

def call_api(sem, name):
    with sem:  # only 3 processes can "call API" at once
        print(f"{name} is making API call...")
        time.sleep(random.uniform(1, 3))
        print(f"{name} finished")

if __name__ == "__main__":
    sem = multiprocessing.Semaphore(1)  # allow 1 concurrent calls
    processes = []

    for i in range(10):
        p = multiprocessing.Process(target=call_api, args=(sem, f"Process-{i}"))
        processes.append(p)
        p.start()

    for p in processes:
        p.join()

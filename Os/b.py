import multiprocessing

def inc1(v):
    for _ in range(100000):
        with v.get_lock():
            v.value += 1  # 
def inc2(v):
    for _ in range(100000):
        v.value += 1  # 


if __name__ == "__main__":
    v = multiprocessing.Value('i', 0)  # shared integer, NOT thread/process safe without lock
    processes = []
    for _ in range(10):
        # p = multiprocessing.Process(target=inc1, args=(v,))
        p = multiprocessing.Process(target=inc2, args=(v,))
        processes.append(p)
        p.start()

    for p in processes:
        p.join()

    print("Expected:", 10 * 100000)
    print("Got:", v.value)
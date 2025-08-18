class cfg:
    def __init__(self):
        self.__temp1 = 0
    
    @property
    def qwert(self):
        return self.__temp1+12.3
    
    @qwert.setter
    def qwert(self, t):
        self.__temp1 = t
    
c = cfg()
print(c.qwert)
c.qwert=120
print(c.qwert)


def deco(some_func):
    def wrapper():
        print("in wrap")
        some_func()
        print("comp wrap")
    print("ulla")
    return wrapper
@deco
def fi():
    print("asdfg")

fi()

def f1():
    for i in range(10):
        yield(i)

f = f1()
print(next(f))
print(next(f))
print(next(f))
import heapq
l=[]
heapq.heappush(l, 1)

heapq.heappush(l, 3)

heapq.heappush(l, -12)

print(l[0])
heapq.heappop(l)

print(l[0])

l=[1,2,3,3,3,4,5]
import bisect
i = bisect.bisect_left(l, 3)
print(i)
i = bisect.bisect_right(l, 3)
print(i)
l.insert(5,23)
print(l)
l.pop(5)
print(l)
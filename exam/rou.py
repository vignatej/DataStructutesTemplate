from functools import lru_cache
ans=0
big=998244353
def add_ans(i):
    global ans
    ans+=i
    ans%=big

# @lru_cache(maxsize=None)
def calc(v, l, r):
    if(l==r):
        add_ans(v)
        return 1
    m=int((l+r)/2)
    a=calc(2*v, l, m)
    b=calc(2*v+1, m+1, r)
    ca=(pow(2, a)-1)*(pow(2, b)-1)
    ca%=big
    ca*=v
    ca%=big
    add_ans(ca)
    return a+b

t=int(input(""))
while(t>0):
    t-=1
    n=int(input(""))
    ans=0
    calc(1, 1, n)
    print(ans)
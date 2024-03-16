import math
def sap(a,n,d):
    return int((n/2) * (2*a + (n-1)*d))

t = int(input(""))
while t>0:
    t-=1
    n, x, y = map(int, input("").split())
    a_s, b_s = int(n/x), int(n/y)
    ans = int(n/(x*y/math.gcd(x, y)))
    a_s -= ans
    b_s -= ans
    fir = sap(n, a_s, -1)
    sec = sap(1, b_s, 1)
    answer = fir - sec
    print(answer)
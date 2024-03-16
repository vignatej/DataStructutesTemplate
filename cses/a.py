with open("cses/f1.txt", 'r') as f1:
    l1 = f1.read().splitlines()
with open("cses/f1.txt", 'r') as f2:
    l2 = f2.read().splitlines()
for i in range(100000):
    if(l1[i]!=l2[i]): print(i)
# print(len(l1), len(l2))

def func(str):
    dict={}
    l = len(str)
    i=0
    while(i<l):
        j=i+1
        while(j<l and str[j]==str[i]):
            j+=1
        c=j-i
        dict[str[i]]=max(dict.get(str[i], 0), c)
        i=j
    out = list(dict.items())
    out.sort(key=lambda x : x[0])
    return out
inp = input("")
print(func(inp))
inp = input("")
for i in inp:
    if(i=='['): i='{'
    elif i==']': i='}'
    print(i, end='')

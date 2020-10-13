# cook your dish here
lst = []
def myremove(x):
    for i in range(len(lst)-1,-1,-1):
        if lst[i] == x:
            lst.pop(i)

for _ in range(int(input())):
    n = int(input())
    lst = list(map(int,input().split()))
    lst.sort(reverse = True)
    if n == 0:
        print(0)
        continue
    if n == 1:
        print(lst[0])
        continue
    final = [lst[-2],lst[-3]]
    if n == 2:
        print(*final)
        continue
    subs = [0,lst[-2],lst[-3],lst[-2]+lst[-3]]
    myremove(lst[-2]+lst[-3])
    lst.pop()
    lst.pop()
    lst.pop()
    while len(lst) >= 1:
        tmp = []
        val = lst[-1]
        final.append(val)
        if len(final) == n:
            break
        for j in range(len(subs)):
            x = val+subs[j]
            tmp.append(x)
            myremove(x)
        subs.extend(tmp)
    print(*final)
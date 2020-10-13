
#https://www.codechef.com/JULY17/problems/IPCTRAIN
class Heap:
    def __init__(slf):
        slf.lst = []
        slf.lst.append([-1,-1,-1])
    def insert(slf,l):
        slf.lst.append(l)
        i = len(slf.lst)-1 
        while int(i/2) >= 1 and slf.lst[i][si] > slf.lst[int(i/2)][si]:
            slf.lst[i],slf.lst[int(i/2)] = slf.lst[int(i/2)],slf.lst[i]
    def delete(slf):
        if len(slf.lst) <= 1:
            return
        slf.lst[1][ti] -= 1 
        if slf.lst[1][ti] != 0:
            return
        slf.lst[1] = slf.lst[-1]
        slf.lst.pop()
        i = 1 
        while i*2+1 < len(slf.lst) and (slf.lst[i*2][si] > slf.lst[i][si] or slf.lst[i*2+1][si] > slf.lst[i][si]):
            if slf.lst[i*2][si] > slf.lst[i*2+1][si]:
                slf.lst[i*2],slf.lst[i] = slf.lst[i],slf.lst[i*2]
                i *= 2
            else:
                slf.lst[i*2+1],slf.lst[i] = slf.lst[i],slf.lst[i*2+1]
                i *= 2 + 1
        if i*2 < len(slf.lst) and (slf.lst[i*2][si] > slf.lst[i][si] or slf.lst[i*2+1][si] > slf.lst[i][si]):
            slf.lst[i*2],slf.lst[i] = slf.lst[i],slf.lst[i*2]
    def calc(slf):
        slf.lst.pop(0)
        summ = 0
        for i in range(len(slf.lst)):
            summ += slf.lst[i][si]*slf.lst[i][ti]
        return summ
        
di,ti,si = 0,1,2    
for _ in range(int(input())):
    heap = Heap()
    n,d = map(int,input().split())
    lst = []
    for _ in range(n):
        lst.append(list(map(int,input().split())))
    lst.sort()
    #print(lst)
    cnt = 1                    
    i = 0
    while cnt <= d:
        while i < n and lst[i][di] <= cnt:
            heap.insert(lst[i])
            i += 1 
        heap.delete()
        cnt += 1 
    print(heap.calc())
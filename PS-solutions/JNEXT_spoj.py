def findmin(lst,n):
    minn = 9
    for i in lst:
        if i > n and i < minn:
            minn = i
    return minn

for _ in range(int(input())):
    n = int(input())
    lst = list(map(int,input().split()))
   
    if lst[-1] > lst[-2]:
        lst[-1],lst[-2] = lst[-2],lst[-1]
        print(''.join(map(str,lst)))
        continue
        
    for i in range(n-3,-1,-1):        
        if lst[i] >= lst[i+1]:
            continue
            
        else:
            val = findmin(lst[i+1:],lst[i])
            l = lst[i:]
            l.remove(val)
            l.sort()
            l.insert(0,val)
            lst[i:] = l
            print(''.join(map(str,lst)))
            break
#statementon the link: https://www.spoj.com/problems/JNEXT/

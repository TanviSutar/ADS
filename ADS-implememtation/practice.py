#https://www.codechef.com/AUG20B/problems/CHEFWED
t = int(input())

for _ in range(t):
    n,k = list(map(int,input().split()))
    f = list(map(int,input().split()))

    if k == 1:
        mset = set()
        table = 1
        psize = 0
        for i in f:
            mset.add(i)
            if(len(mset) == psize):
                table += 1
                mset.clear()
                psize = 1
                mset.add(i)
            else:
                psize += 1
        print(table)
        continue

    cppl = 0
    reparr = [0]*n
    dict1 = dict()
    for i in range(n-1,-1,-1):
        #print(i)
        if f[i] in dict1:
            if dict1[f[i]] >= 2: cppl += 1
            else: cppl += 2
            dict1[f[i]] += 1
        else:
            dict1[f[i]] = 1
        reparr[i] = cppl

    #print(reparr)

    cppl = 0
    dict1.clear()
    tables = 1
    finalppl = 0
    flag = 0
    for i in range(n):
        if f[i] in dict1:
            if dict1[f[i]] >= 2: cppl += 1
            else: cppl += 2
            dict1[f[i]] += 1
        else: dict1[f[i]] = 1
        if cppl > k:
            dict1.clear()
            dict1[f[i]] = 1
            finalppl += cppl-1
            if(reparr[i] <= k): 
                if flag == 0: break
                else: finalppl += reparr[i]
                break
            cppl = 0
            tables += 1
            flag = 1#atleast 2 tables used
    if flag == 0: print(k+reparr[0])                                                             
    else: print(tables*k+finalppl)
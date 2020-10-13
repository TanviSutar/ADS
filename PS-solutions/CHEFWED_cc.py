t = int(input())
for _ in range(t):
    n,k = list(map(int,input().split()))
    f = list(map(int,input().split()))

    if k == 1:
        mset = set()
        psize = 0
        tables = 1
        for i in f:
            mset.add(i)
            if psize == len(mset):
                tables += 1
                mset.clear()
                mset.add(i)
                psize = 1
            else: psize = len(mset)
        print(tables)
        continue

    cppl = 0
    reparr = [0]*n
    dict1 = dict()
    for i in range(n-1,-1,-1):
        if f[i] in dict1:
            if dict1[f[i]] >= 2: cppl += 1
            else: cppl += 2
            dict1[f[i]] += 1
        else:
            dict1[f[i]] = 1
        reparr[i] = cppl

    if len(dict1) == 1:#all from same family
        print(k+reparr[0])
        continue
    
    if k >= reparr[0]:
        print(k+reparr[0])
        continue
    
    cost = k
    if k%2 != 0:
        k += 1

    dict1.clear()
    prevcppl = 0
    tables = 1
    cppl = 0
    finalppl = 0
    for i in range(n):
        if f[i] in dict1:
            if dict1[f[i]] >= 2: cppl += 1
            else: cppl += 2
            dict1[f[i]] += 1
        else: dict1[f[i]] = 1
        if cppl > k:
            if reparr[i] <= k:
                i += 1
                while(i<n):
                    if f[i] in dict1:
                        if dict1[f[i]] >= 2: cppl += 1
                        else: cppl += 2
                        dict1[f[i]] += 1
                    else: dict1[f[i]] = 1
                    i += 1
                finalppl += cppl
                break
            finalppl += prevcppl
            cppl = 0
            dict1.clear()
            dict1[f[i]] = 1
            tables += 1
        prevcppl = cppl
    #print(finalppl,tables,k)
    a = min((cost+reparr[0]),(tables*cost+finalppl))
    print(a)

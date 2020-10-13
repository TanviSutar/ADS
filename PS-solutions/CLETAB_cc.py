# cook your dish here
for _ in range(int(input())):
    n,m = list(map(int,input().split()))
    lst = list(map(int,input().split()))
    tmp = []
    count = 0
    for i in range(len(lst)):
        if lst[i] not in tmp:
            if n > 0:
                tmp.append(lst[i])
                lst[i] = -1 
                count += 1
                n -= 1 
                continue
            farthest = 0
            ind = 0
            for j in range(len(tmp)): 
                if tmp[j] not in lst:
                    tmp[j] = lst[i]
                    lst[i] = -1 
                    count += 1
                    break
                val = lst.index(tmp[j])
                if val > farthest:
                    farthest = val
                    ind = j
            else:
                tmp[ind] = lst[i]
                lst[i] = -1
                count += 1
                #print(count,tmp[j])
        else:
            lst[i] = -1
        print(tmp)
        print(lst)
    print(count)
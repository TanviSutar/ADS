def recur(lst,n,memo):
    if n >= len(lst):
        return 0
    i = lst[n]-1
    j = lst[n]+1
    while memo[i] != 1 or memo[j] != 1:
        if memo[i] == 0:
            i -= 1
        if memo[j] == 0:
            j += 1
    count = lst[n]-i + j-lst[n]
    memo[lst[n]] = 1
    return count + recur(lst,n+1,memo)
    
from itertools import permutations
for _ in range(int(input())):
    n,m = list(map(int,raw_input().split()))
    perm = list(permutations(range(1,n+1)))
    minn = m
    for i in perm:
        memo = [0]*n
        memo.insert(0,1)
        memo.append(1) 
        val = recur(i,0,memo)
        print('val: ',val)
        if m - val >= 0 and m - val < minn:
            minn = m-val
    if minn == m:
        print(-1)
    else: 
        print(minn)   

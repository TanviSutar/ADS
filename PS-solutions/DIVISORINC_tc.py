import math
def factors(n):
    lst = []
    for i in range(2,int(math.sqrt(n))+1):
        if not n%i:
            lst.append(i)
            if int(n/i) != i:
                lst.append(int(n/i))
    return lst

def divisorInc(n,m,count,memo):
    if n == m:
        return count
    if n > m:
        return 999
    if memo[n] != -1:
        return memo[n]
    fctrs = factors(n)
    fctrs.sort(reverse=True)
    minn = 999
    for i in fctrs:
        val = divisorInc(i+n,m,count+1,memo)
        if i+n < len(memo):
            memo[i+n] = val
            if val < minn:
                minn = val
    return minn

n,m = list(map(int,raw_input('Enter two integer values: ').split()))
memo = [-1]*(m+1)
val = divisorInc(n,m,0,memo)
if val != 999:
    print(val)
else:
    print(-1)

#https://community.topcoder.com/stat?c=problem_statement&pm=6186&rd=9823
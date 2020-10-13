def catalan(n):
    if n <= 1:
        return 1
    res = 0
    for i in range(n):
        res = res + catalan(i)*catalan(n-1-i)
    return res

n = int(input())
print(catalan(n))     

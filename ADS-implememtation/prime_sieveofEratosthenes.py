import math
def find_prime(n):
    lst = [1]*(n+1)
    lst[0] = 0
    lst[1] = 0
    for i in range(2,int(math.sqrt(n))+1):
        if lst[i]:
            j = 2
            while i*j <= n:
                lst[i*j] = 0
                j += 1
    for i in range(len(lst)):
        if lst[i]:
            print(i)

inp = int(input())
print('Prime numbers in the range 1-{}:'.format(inp))
find_prime(inp)

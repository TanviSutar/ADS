def fibonacci(n,lst):
    if lst[n] != -1:
        return lst[n]
    lst[n] = fibonacci(n-1,lst)+fibonacci(n-2,lst)
    return lst[n]

def fib(n):
    if n<=1:
        return n
    return fib(n-1)+fib(n-2)

n = int(input())
lst = [-1]*(n-2)
lst.insert(0,0)
lst.insert(1,1)
print(fibonacci(n-1,lst))
print('*********************************')
print(fib(n-1))
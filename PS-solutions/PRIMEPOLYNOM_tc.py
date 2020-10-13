import math
def prime(n):
    for i in range(2,int(math.sqrt(n))+1):
        if not n%i:
            return False
    return True

def primepoly(a,b,c):
    if c < 0 or not prime(c):
        return 0
    i = 1
    while True:
        if not prime(a*i**2 + b*i + c):
            return i
        i += 1

a,b,c = list(map(int,raw_input('Enter the values for a,b and c: ').split()))
print(primepoly(a,b,c))
#https://community.topcoder.com/stat?c=problem_statement&pm=4475&rd=8012
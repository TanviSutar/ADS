#incomplete
import math
import numpy
from itertools import permutations

def isprime(n):
    if n <= 1:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if not n%i:
            return False
    return True

def prime_fact(n):
    lst = []
    for i in range(2,n):
        while not n%i:
            lst.append(i)
            n = int(n/i)
        if n <= 1:
            break
    #print(lst)
    perm = list(permutations(lst))
    #print(perm)
    if len(perm) == 2:
        return [perm[0][0],perm[0][1]]
    else:
        lst1 = [lst]
        for each in perm:
            for i in range(1,len(perm)):
                for j in range(i,len(perm)):
                    fno = numpy.prod(each[0:i])
                    sno = numpy.prod(each[i:len(perm)])
                    tmp = [fno,sno]
                    tmp.sort()
                    if tmp not in lst1:
                        lst1.append(tmp)
    return lst1

n = int(input('Enter an integer value: '))
print(prime_fact(n))

#https://community.topcoder.com/stat?c=problem_statement&pm=2986&rd=5862
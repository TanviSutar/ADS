from itertools import permutations
import math
def isprime(n):
    if n == 1:
        return False
    for i in range(2,int(math.sqrt(n)+1)):
        if not n%i:
            return False
    return True

def func(n):
    perm = list(permutations(n))
    no1,no2,no3 = 999,999,999
    for each in perm:
        for i in range(1,len(each)-1):
            for j in range(i+1,len(each)):
                if not each[0]:
                    break
                if not each[i] or not each[j]:
                    continue
                fno = int(''.join(list(map(str,each[0:i]))))
                sno = int(''.join(list(map(str,each[i:j]))))
                tno = int(''.join(list(map(str,each[j:len(each)]))))
                if isprime(fno) and isprime(sno) and isprime(tno):
                    if (fno*sno*tno) < (no1*no2*no3):
                        no1,no2,no3 = fno,sno,tno
    return [no1,no2,no3]


lst = list(map(int,list(input())))
nlst = func(lst)
if nlst[0] == 999:
    print('{}')
else:
    print(set(nlst))

#https://community.topcoder.com/stat?c=problem_statement&pm=3458&rd=5869
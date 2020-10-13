import math
def primeFactors(n):
    i = 2
    while n>1:
        count = 0
        while not n%i:
            count += 1
            n = n/i 
        if count > 0:
            print('{}^{}'.format(i,count),' ',end='')
        i += 1
    print()

n = int(input('Enter a decimal number: '))
print('The prime factors of the given numer is: ',end='')
primeFactors(n)
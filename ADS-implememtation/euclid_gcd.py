def euclid_gcd(a,b):
    if b == 0:
        return a
    elif a == 0:
        return b
    return euclid_gcd(b,a%b)

a,b = list(map(int,input('Enter two numbers to find thier GCD: ').split())) 
print('GCD of {} and {} is:'.format(a,b),euclid_gcd(a,b)) 
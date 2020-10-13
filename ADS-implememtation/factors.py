import math
def find_factors(n):
    for i in range(1,int(math.sqrt(n))+1):
        if not n%i:
            print(i)
            if i != n/i:
                print(int(n/i))

inp = int(input('Enter a number to find its factors: '))
find_factors(inp)
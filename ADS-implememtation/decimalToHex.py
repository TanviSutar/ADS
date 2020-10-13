def decimalToHex(n):
    lst = []
    alpha = ['A','B','C','D','E','F']
    while n > 0:
        if n%16 >= 10:
            lst.append(alpha[(n%16)%10])
        else:
            lst.append(n%16)
        n = int(n/16)
    return lst[::-1]

n = int(input('Enter a decimal number: '))
print('Hexadecimal form of the given number is: ')
lst = list(map(str,decimalToHex(n)))
print(''.join(lst))
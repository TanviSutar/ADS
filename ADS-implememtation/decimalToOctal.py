def decimalToOctal(n):
    lst = []
    while n > 0:
        lst.append(n%8)
        n = int(n/8)
    return lst[::-1]

n = int(input('Enter a decimal number: '))
print('Octal form of the given decimal number: ')
lst = list(map(str,decimalToOctal(n)))
print(''.join(lst))
def hexToDecimal(n):
    val = 0 
    n = n[::-1]
    alpha = {'A':10,'B':11,'C':12,'D':13,'E':14,'F':15}
    for i in range(len(n)):
        if n[i].isalpha():
            val += alpha[n[i]] * 16**i
        else:
            val += int(n[i]) * 16**i
        i += 1
    return val

n = raw_input('Enter a hexadecimal number: ')
print('The decimal conversion of the given hexadecimal number: ')
print(hexToDecimal(n))
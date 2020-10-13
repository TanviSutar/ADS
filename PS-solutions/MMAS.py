def evaluate(stk):                                              
    top = len(stk)-1
    mass = 0
    dict1 = {'H':1,'C':12,'O':16}
    val = 0

    while top >= 0:
        if stk[top].isalpha():
            if val > 0:
                mass += dict1[stk[top]]*val
                val = 0
            else:
                mass += dict1[stk[top]]
            top -= 1
        elif stk[top].isnumeric():
            val = int(stk[top])
            top -= 1
        else:
            temp = top
            top -= 1
            bal = 1
            while True:
                if bal == 0:
                    break
                if stk[top] == '(':
                    bal -= 1
                elif stk[top] == ')':
                    bal += 1                         
                top -= 1
            m = evaluate(stk[top+2:temp])
            if val > 0:
                mass += m*val
                val = 0
            else:
                mass += m
    return mass

lst = list(input())
print(evaluate(lst))
#problem stat link: https://www.spoj.com/problems/MMASS/
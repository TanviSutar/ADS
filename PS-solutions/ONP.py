for i in range(int(input())):
    lst = list(input())
     
    stk = []
    top = -1
    oppr = {'+':1,'-':1,'*':2,'/':2,'^':3}

    for i in lst:
        if i == '(':
            stk.append(i)
            top += 1
        elif i in list(oppr.keys()):
            stk.append(i)
            top += 1
            var = top-1
            if stk[var] != '(':
                while oppr[i] < oppr[stk[var]]:
                        stk[var+1] = stk[var]
                        var -= 1
                stk.insert(var+1,i)
        elif i.isalpha():
            print(i,end='')
        else:
            while True:
                if stk[top] == '(':
                    a = stk.pop()
                    top -= 1
                    break
                print(stk.pop(),end='')
                top -= 1
    print()
    
#Problem stat link: https://www.spoj.com/problems/ONP/
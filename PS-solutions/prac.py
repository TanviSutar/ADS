from itertools import product

t = int(input())
perms = list(product([0,1,2,3,4,5],repeat = t))
count = 0
for j in perms:
    if count >= 115: break
    strt = 1
    for i in j:
        tmp = strt
        print i,
        for k in range(1,11):
            tmp = tmp + i
            print tmp,'\t',
        print('\n')
        strt = strt + 1
    print('\n\n')
    count = count +1

print count,'END'
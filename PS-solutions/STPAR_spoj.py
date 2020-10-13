n = int(input())

lst = list(map(int,input().split()))

stk = []
ans = []
top = -1

a = input()

i=1
while i<=n:
    if min(lst) == lst[i]:
        ans.append(lst[i])
        lst[i] = 1001
        i += 1
    elif top != -1 and stk[top] == min(lst):
        ans.append(stk.pop())
        top -= 1
        lst[lst.index(min(lst))] = 1001
    else:
        stk.append(lst[i])
        top += 1
        i += 1

if stk:
    ans += stk[-1]

if ans == list(range(1,n+1)):
    print('yes')
else:
    print('no')

#problem statement link: https://www.spoj.com/problems/STPAR/
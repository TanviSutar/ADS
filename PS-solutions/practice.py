# cook your dish here
t = int(input())
for _ in range(t):
    s = input().split();
    x1,y1 = list(map(int,input().split()))
    q = int(input())
    for _ in range(q):
        x2,y2 = list(map(int,input().split()))
        x = x2-x1
        y = y2-y1
        cntx = 0
        cnty = 0
        for i in s:
            if cntx < abs(x):
                if ((x < 0 and i == 'L') or (x > 0 and i == 'R')): cntx += 1
            if cnty < abs(y):
                if ((y < 0 and i == 'D') or (y > 0 and i == 'U')): cnty += 1
            if (cntx >= abs(x) and cnty >= abs(y)): break
        if (cntx >= abs(x) and cnty >= abs(y)): print('YES ',abs(x)+abs(y))
        else: print('NO')
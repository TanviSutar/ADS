def calc_menus(n):
    mprice = [1,2,4,8,16,32,64,128,256,512,1024,2048]
    count = 0
    while n >= mprice[-1]:
        n -= mprice[-1]
        count += 1
    while n >= 1:
        high = 11
        low = 0
        while high-low > 1:
            mid = (high+low)//2
            if mprice[mid] <= n:
                low = mid
            else:
                high = mid
        n -= mprice[low]
        count += 1
    return count

for _ in range(int(input())):
    n = int(input())
    print(calc_menus(n))
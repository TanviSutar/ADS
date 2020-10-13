#maximal subarray
#kadane's algo
strr = list(map(int,raw_input().split()))
curr = 0 
answer = -10**9
lst = []
x = 0
y = 0
for j in range(len(strr)):
    if j != 0 and strr[j-1] < 0:
        x = j
    curr = max(curr+strr[j],strr[j])
    y = strr[j]
    if answer < curr:
        answer = max(answer,curr)
        lst = strr[x:y]
    #print(curr,j)
    #print(answer)
print('Answer: ',answer)
print(lst)#typo here, fix it
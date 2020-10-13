import heapq
for _ in range(int(input())):
    n,k1,k2,k3 = map(int,input().split())
    arr = list(map(int,input().split()))
    cumulat = [0]
    summ = 0
    heap = []
    for i in range(len(arr)):
        summ += arr[i]
        for j in cumulat:
            heapq.heappush(heap,summ-j)
            if len(heap) > max(k1,k2,k3):
                heapq.heappop(heap)
        if len(cumulat) < max(k1,k2,k3):
            cumulat.append(summ)
        else:
            if cumulat[-1] > summ:
                cumulat[-1] = summ
                i = len(cumulat)-2
                while cumulat[i] > cumulat[i+1] and i >= 0:
                    cumulat[i],cumulat[i+1] = cumulat[i+1],cumulat[i]
                    i -= 1
    heap.sort(reverse=True)
    #print(heap)
    #print(cumulat)
    print(heap[k1-1],heap[k2-1],heap[k3-1])
        
# array implementation of max heaps
class MaxHeap:
    def __init__(slf,cap):
        slf.cap= cap
        slf.lst = []
        slf.lst.append(0)
    def insert(slf,val):
        if len(slf.lst) >= slf.cap+1:
            print('Maximum capacity reached.')
            return -1
        slf.lst.append(val)
        i = len(slf.lst)-1
        slf.lst[0] += 1
        while int(i/2) >= 1 and slf.lst[int(i/2)] < slf.lst[i]:
            slf.lst[int(i/2)],slf.lst[i] = slf.lst[i],slf.lst[int(i/2)]
            i = int(i/2)
        return 0
    def delete(slf):
        if len(slf.lst) <= 1:
            print('No element to delete.')
            return -1
        tmp = slf.lst[1]
        slf.lst[1] = slf.lst[-1]
        slf.lst[0] -= 1
        slf.lst.pop()
        i = 1
        while i*2+1 < len(slf.lst):
            if slf.lst[i] < slf.lst[i*2] or slf.lst[i] < slf.lst[i*2+1]:
                if slf.lst[i*2] > slf.lst[i*2+1]:
                    slf.lst[i*2],slf.lst[i] = slf.lst[i],slf.lst[i*2]
                    i *= 2
                else:
                    slf.lst[i*2+1],slf.lst[i] = slf.lst[i],slf.lst[i*2+1]
                    i *= 2 +1
        if i*2 < len(slf.lst) and slf.lst[i] < slf.lst[i*2]:
            slf.lst[i*2],slf.lst[i] = slf.lst[i],slf.lst[i*2]
        return tmp 
    def peek(slf):
        return slf.lst[1]
    def show(slf):
        print(slf.lst)

i = int(input('Enter the capacity of priority queue: '))
obj = MaxHeap(i)
print('1. Insert\t2. Delete\t3. Peek\t4. Exit')
i = int(input())
while i < 4 and i > 0:
    if i == 1:
        val = int(input('Enter the number to be inserted: '))
        obj.insert(val)
    elif i ==2:
        tmp = obj.delete()
        if tmp != -1:
            print('Number deleted from priority queue: ',tmp)
    elif i == 3:
        print('Number at the top of priority queue: ',obj.peek())
    i = int(input())
#obj.show()
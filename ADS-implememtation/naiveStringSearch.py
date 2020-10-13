def search(txt,pat):
    count = 0
    j = 0
    for i in range(len(txt)):
        for j in pat:
            if j != txt[i] or i >= len(txt):
                break
            i += 1
        else:
            count += 1
    return count

lst = raw_input().split()
print(search(lst[0],lst[1]))

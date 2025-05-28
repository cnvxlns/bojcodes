import sys
input = sys.stdin.readline

a = []

for i in range(9):
    a.append(int(input()))

for i in range(1, 1 << 10):
    lst = []
    cnt = 0
    sum = 0
    for j in range(10):
        if i & (1 << j):
            cnt += 1
            sum += a[j]
            lst.append(a[j])
    if sum == 100 and cnt == 7:
        lst.sort()
        for i in lst:
            print(i)
        break
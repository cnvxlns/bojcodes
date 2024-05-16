import sys
input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

arr.sort(reverse = True)

M = float(arr[0])
sum = 0.

for i in range(n):
    arr[i] = float(arr[i]) / M * 100.00
    sum += float(arr[i])

print(sum / float(n))



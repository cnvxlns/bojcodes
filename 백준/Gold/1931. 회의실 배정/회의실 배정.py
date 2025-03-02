import sys
input = sys.stdin.readline

N = int(input())

arr = list(tuple(map(int, input().split())) for _ in range(N))

arr.sort(key = lambda x:(x[1],int(x[0])))

last = 0
cnt = 0

for i in range(N):
    if last <= arr[i][0]:
        #print(arr[i][0])
        last = arr[i][1]
        cnt += 1
    
print(cnt)



import sys

sys.setrecursionlimit(10000000)

inf = 0x7f7f7f7f

input = sys.stdin.readline

N, K = map(int, input().split())

B = [tuple(map(int, input().split()))for _ in range(N)]

dp = [[0] * 100500 for _ in range(105)]

W = 0

for i in range(N):
    for j in range(1, K + 1):
        w = B[i][0]
        v = B[i][1]
        if j < w:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v)

print(dp[N - 1][K])
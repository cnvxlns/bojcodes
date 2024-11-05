import sys
input=sys.stdin.readline
T = int(input())
dp = [0] * 1000010
dp[1] = 1
dp[2] = 2
dp[3] = 4

mod = int(1e9+9)

for i in range(4, 1000001):
    dp[i] = (dp[i-1]%mod + dp[i-2]%mod + dp[i-3]%mod) % mod
for _ in range(T):
    n = int(input())
    print(dp[n])    
import sys
input = sys.stdin.readline

n = int(input())

def dp(n):
    if n <= 1:
        return 0
    if n % 2 == 1:
        return dp(n // 2) + dp(n // 2 + 1) + (n // 2) * (n // 2 + 1)
    else:
        return dp(n // 2) * 2 + (n // 2) * (n // 2)


print(dp(n))
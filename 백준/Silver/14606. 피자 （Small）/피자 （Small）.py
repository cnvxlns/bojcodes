cache = [0] * 100

cache[2] = 1
cache[3] = 3


def dp(N):
	if N <= 1:
		return 0
	if cache[N]:
		return cache[N]
	if N % 2:
		cache[N] = (N // 2) * (N // 2 + 1) + dp(N // 2) + dp(N // 2 + 1)
		return cache[N]
	else:
		cache[N] = (N // 2) * (N // 2) + dp(N // 2) * 2
		return cache[N]

N = int(input())
print(dp(N))
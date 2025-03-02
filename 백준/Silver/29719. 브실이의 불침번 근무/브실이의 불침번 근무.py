n, m = map(int, input().split())
mod = 1000000007

def pow(n, m):
	if n == 1:
		return 1
	if m == 1:
		return n
	if m == 0:
		return 1
	ret =  pow(n, m // 2) % mod
	if m % 2:
		return (((ret * ret) % mod ) * n ) % mod
	else:
		return ret * ret % mod
	
	
ans = pow(m, n) % mod
ans -= pow(m - 1, n)
ans %= mod

print(ans)
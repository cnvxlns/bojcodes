n = int(input())

i = 0
ans = 0

while (1 << i) <= n:
    if n & (1 << i):
        ans += 1
    i += 1

print(ans)
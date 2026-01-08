import sys
input = sys.stdin.readline

n = int(input())

cache = [0] * 95

cache[1] = 1
cache[2] = 1

for i in range(3, n + 1):
    cache[i] = cache[i - 1] + cache[i - 2]

print(cache[n])


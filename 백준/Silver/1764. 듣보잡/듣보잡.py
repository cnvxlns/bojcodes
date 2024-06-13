import sys
input = sys.stdin.readline

n, m = map(int, input().split())

a = set(input().strip() for _ in range(n))

dbj = list()

for i in range(m):
    q = input().strip()
    if q in a:
        dbj.append(q)

dbj.sort()
print(len(dbj))
print(*dbj, sep = "\n")
    


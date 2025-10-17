def solve():
    s, copy = input().split()
 
    print(len(s) - len(copy) * s.count(copy) + s.count(copy))


    


n = int(input())

for i in range(n):
    solve()
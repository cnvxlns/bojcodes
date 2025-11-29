import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

n = int(input())

a = list([] for _ in range(n + 1))

graph = [[] for _ in range(n + 1)]

for i in range(n):
    line = list(map(int, input().split()))
    curnode = line[0]
    for i in range(1, len(line) - 1, 2):
        node = line[i]
        dist = line[i + 1]
        graph[curnode].append((node, dist))

def dfs(start):
    stk = []

    stk.append((start, 0))
    visited = [-1] * (n + 1)

    visited[start] = 0
    
    maxdist = 0
    farthestnode = start


    while stk:
        curnode, curdist = stk.pop()
        if curdist > maxdist:
            maxdist = curdist
            farthestnode = curnode

        for nextnode, weight in graph[curnode]:
            if visited[nextnode] == -1:
                nextdist = curdist + weight
                visited[nextnode] = nextdist
                stk.append((nextnode, nextdist))

    return farthestnode, maxdist    

node1, dist1 = dfs(1)
node2, ans = dfs(node1)

print(ans)    


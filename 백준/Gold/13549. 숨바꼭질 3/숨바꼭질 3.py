import sys
import heapq

inf = 0x7f7f7f7f

input = sys.stdin.readline

N, K = map(int, input().split())
G = [[] for _ in range(100100)]
dist = [inf] * 100100

def makeGraph():
    for i in range(0, 100000):
        G[i].append((1, i + 1))
    for i in range(1, 100001):
        G[i].append((1, i - 1))
    for i in range(1, 50001):
        G[i].append((0, i * 2))

def dijkstra(start):
    global K
    dist[start] = 0
    Q = []
    heapq.heappush(Q, (0, start))
    while Q:
        curdist, curnode = heapq.heappop(Q)
        if dist[curnode] < curdist:
            continue
        for nextdist, nextnode in G[curnode]:
            if nextnode > 100000 or nextnode < 0:
                continue
            newdist = curdist + nextdist
            if newdist < dist[nextnode]:
                dist[nextnode] = newdist
                heapq.heappush(Q, (newdist, nextnode))


makeGraph()
dijkstra(N)

print(dist[K])
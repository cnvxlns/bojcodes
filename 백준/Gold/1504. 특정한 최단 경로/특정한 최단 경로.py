import sys
input = sys.stdin.readline
import heapq

inf = 0x7f7f7f7f

N, E = map(int, input().split())

G = [[]for _ in range (N + 1)]
dist = [inf] * (N + 1)

for i in range(E):
	a, b, c = map(int, input().split())
	G[a].append((c, b))
	G[b].append((c, a))
	
v1, v2 = map(int, input().split())

def dijkstra(start):
	dist[start] = 0
	Q =[]
	heapq.heappush(Q, (0, start))
	while Q:
		curdist, curnode = heapq.heappop(Q)
		if curdist > dist[curnode]:
			continue
		for newdist, newnode in G[curnode]:
			d = curdist + newdist
			if d < dist[newnode]:
				dist[newnode] = d
				heapq.heappush(Q, (d, newnode))


dijkstra(1)
d1 = dist[v1]
d2 = dist[v2]


dist = [inf] * (N + 1)
dijkstra(v1)
d1 += dist[v2]
d2 += dist[N]


dist = [inf] * (N + 1)
dijkstra(v2)
d1 += dist[N]
d2 += dist[v1]

if d1 >= inf and d2 >= inf:
	print(-1)
else:
	if d1 < d2:
		print(d1)
	else :
		print(d2)
	
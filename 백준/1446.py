import sys
import heapq
from collections import defaultdict
n,d = map(int,input().split())
adj = defaultdict(list)
for i in range(n):
    a,b,c = map(int,input().split())
    adj[a].append((b,c))

dist = [int(1e15)]*(10001)
pq = []
heapq.heappush(pq,(0,0))
dist[0]=0
while pq:
    cost,cur = heapq.heappop(pq)
    if dist[cur]<cost:continue
    for i in range(len(adj[cur])):
        next = adj[cur][i][0]
        ncost = adj[cur][i][1]+cost
        if next<=d and dist[next]>ncost:
            dist[next]=ncost
            heapq.heappush(pq,(ncost,next))
    if cur+1<=d and dist[cur+1]>cost+1:
        heapq.heappush(pq,(cost+1,cur+1))
        dist[cur+1]=cost+1
print(dist[d])



    


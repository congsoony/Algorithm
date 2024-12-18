from collections import deque
n= int(input())
m = int(input())
adj = [[] for i in range(n+1)]
indegree =[0]*(n+1)
outdegree =[0]*(n+1)
res = [0]*(n+1)
for i in range(m):
    a,b,c =map(int,input().split())
    adj[a].append((b,c))
    indegree[b]+=1
    outdegree[a]+=1

q =deque()
q.append(n)
res[n]=1
while q:
    cur = q.popleft()
    for i in range(len(adj[cur])):
        next = adj[cur][i][0]
        indegree[next]-=1
        nextcost =  res[cur]*adj[cur][i][1]
        res[next]+=nextcost
        if indegree[next]==0:
            q.append(next)
for i in range(1,n):
    if outdegree[i]==0:
        print('{} {}'.format(i,res[i]))

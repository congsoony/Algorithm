from collections import deque , defaultdict
Test = int(input())
for test in range(1,Test+1):
    k,m,p = map(int,input().split())
    adj = [[]for i in range(m+1)]
    indegree = [0]*(m+1)
    strahler = [0]*(m+1)
    d = defaultdict(list)
    for i in range(p):
        a,b = map(int,input().split())
        adj[a].append(b)
        indegree[b]+=1
    q = deque()
    for i in range(1,m):
        if indegree[i]==0:
            q.append(i)
            strahler[i]=1

    while q:
        cur = q.popleft()
        for next in adj[cur]:
            indegree[next]-=1
            d[next].append(strahler[cur])
            if indegree[next]==0:
                q.append(next)
                _max = max(d[next])
                maxcnt = d[next].count(_max)
                strahler[next]=_max if maxcnt==1 else _max+1
    print(k,strahler[m])

from collections import deque
f,s,g,u,d = map(int,input().split())
def isrange(c):
    return 1<=c<=f

def bfs():
    check=[0]*(f+1)
    q = deque()
    check[s]=1
    q.append(s)
    while q:
        cur = q.popleft()
        if g ==cur:
            return check[cur]-1
        
        for next in [cur+u,cur-d]:
            if isrange(next) and check[next]==0:
                q.append(next)
                check[next]=check[cur]+1
    
    return "use the stairs"

print(bfs())

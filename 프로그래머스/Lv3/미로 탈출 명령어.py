from collections import deque
def solution(n, m, x, y, r, c, k):
    answer = []
    x,y =y,x
    dis = abs(r-y)+abs(x-c)
    if k<dis or (dis-k)%2==1:
        return "impossible"
    def getdis(y1,x1):
        return abs(y1-r)+abs(x1-c)
    def isrange(y1,x1):
        return 1<=y1<=n and 1<=x1<=m
    q = deque()
    q.append((y,x,0))
    dy=[1,0,0,-1]
    dx=[0,-1,1,0]
    ds="dlru"
    while q:
        y,x,cnt =q.pop()
        if y==r and x==c and cnt==k:
            break
        for i in range(4):
            ny =y+dy[i]
            nx=x+dx[i]
            if isrange(ny,nx):
                if getdis(ny,nx)+cnt+1 <=k:
                    q.append((ny,nx,cnt+1))
                    answer.append(ds[i])
                    break    
    return ''.join(answer)
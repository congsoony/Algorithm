import heapq
def solution(n, m, hole):
    dy,dx=[-1,0,1,0],[0,1,0,-1]
    board = [[0]*m for i in range(n)]
    for h in hole:
        board[h[0]-1][h[1]-1]=1
    dist=[[[int(1e8)]*2 for i in range(m)] for j in range(n)]
    pq =[]
    def isrange(y,x):
        return 0<=y<n and 0<=x<m
    pq.append((0,0,0,0))
    dist[0][0][0]=0
    while pq:
        cost,y,x,flag = heapq.heappop(pq)
        if dist[y][x][flag]<cost:
            continue
        for i in range(4):
            ny =y+dy[i]
            nx= x+dx[i]
            if isrange(ny,nx) and board[ny][nx]==0 and dist[ny][nx][flag]>cost+1:
                pq.append((cost+1,ny,nx,flag))
                dist[ny][nx][flag]=cost+1
            if flag==0:
                ny =y+dy[i]*2
                nx = x+dx[i]*2
                if isrange(ny,nx) and board[ny][nx]==0 and dist[ny][nx][1]>cost+1:
                    pq.append((cost+1,ny,nx,1))
                    dist[ny][nx][1]=cost+1
    if min(dist[n-1][m-1][0],dist[n-1][m-1][1])==int(1e8):
        return -1
    return min(dist[n-1][m-1][0],dist[n-1][m-1][1])
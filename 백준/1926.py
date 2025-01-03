import sys
sys.setrecursionlimit(3000000)
n,m = map(int,input().split())
board = [list(map(int,input().split())) for i in range(n)]
res =0
cnt = 0
dy,dx=[-1,0,1,0],[0,1,0,-1]

def dfs(y,x):
    board[y][x]=0
    total = 1
    for i in range(4):
        ny = y+dy[i]
        nx= x+dx[i]
        if 0<=ny<n and 0<=nx <m and board[ny][nx]:
                total+=dfs(ny,nx)
    return total
for i in range(n):
    for j in range(m):
        if board[i][j]:
            cnt+=1
            res = max(res,dfs(i,j))

print(cnt)
print(res)

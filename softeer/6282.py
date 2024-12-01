from collections import deque
n = int(input())
board = [[int(c) for c in input()] for i in range(n)]
res = []
dy,dx = [-1,0,1,0],[0,1,0,-1]
def isrange(y,x):
    return 0<=y<n and 0<=x<n
def dfs(y,x):
    global board
    if not isrange(y,x):
        return 0
    if not board[y][x]:
        return 0
    board[y][x]=0
    total = 1
    for i in range(4):
        ny =y+dy[i]
        nx =x+dx[i]
        total+=dfs(ny,nx)
    return total

for i in range(n):
    for j in range(n):
        if board[i][j]:
            res.append(dfs(i,j))

res.sort()
print(len(res))
print('\n'.join(map(str,res)))

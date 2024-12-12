import sys
from collections import deque

n,m,k = map(int,input().split())
board = [list(map(int,input().split())) for i in range(n)]
time  = [[0]*m for i in range(n)]
dy=[0,1,0,-1]
dx=[1,0,-1,0]

dy2=[-1,-1,-1,0,0,1,1,1]
dx2=[-1,0,1,-1,1,-1,0,1]

def attackSelection():
    global n,m,k,board,time
    l=[]
    for i in range(n):
        for j in range(m):
            if board[i][j]>0:
                l.append((board[i][j],-time[i][j],-(i+j),-j,i,j)) #공격력가장낮은,가장최근,행과열합이가장큰,열값이 가장큰
    l.sort()
    if len(l)<=1:
        return -1,-1,-1,-1
    return l[0][4],l[0][5],l[-1][4],l[-1][5]

def bfs(ay,ax,fy,fx):
    global n,m,k,board,time,dy,dx
    check = [[0]*m for i in range(n)]
    q = deque()
    check[ay][ax] = (ay,ax)
    q.append((ay,ax))
    
    while q:
        y,x = q.popleft()
        if y==fy and x==fx:
            break
        for i in range(4):
            ny =(n + y+dy[i])%n
            nx =(m + x+dx[i])%m
            if board[ny][nx]>0 and not check[ny][nx]:
                q.append((ny,nx))
                check[ny][nx]=(y,x)
    path = []
    if not check[fy][fx]:
        return path
    y,x =fy,fx
    path.append((fy,fx))
    while True:
        if y==ay and x==ax:
            break
        path.append(check[y][x])
        y,x= check[y][x]
    path.reverse()
    return path
def heal(check):
    global n,m,k,board,time,dy2,dx2
    for i in range(n):
        for j in range(m):
            if board[i][j]>0 and check[i][j]==0:
                board[i][j]+=1
def laserattck(path):
    global n,m,k,board,time,dy2,dx2
    check = [[0]*m for i in range(n)]
    ay,ax =path[0]
    fy,fx = path[-1]
    for i in range(1,len(path)-1):
        y,x =path[i]
        board[y][x] -=board[ay][ax]//2
        check[y][x]=1
    board[fy][fx]-=board[ay][ax]
    check[fy][fx]=check[ay][ax]=1
    heal(check)
def bombattack(ay,ax,fy,fx):
    global n,m,k,board,time,dy2,dx2
    board[fy][fx]-=board[ay][ax]
    check = [[0]*m for i in range(n)]
    check[fy][fx]=check[ay][ax] =1
    for i in range(8):
        ny =(n + fy+dy2[i])%n
        nx =(m + fx+dx2[i])%m
        if check[ny][nx]==0:
            board[ny][nx]-=board[ay][ax]//2
        check[ny][nx]=1
    heal(check)

for t in range(1,k+1):
    ay,ax,fy,fx = attackSelection()
    if ay==-1:
        break
    board[ay][ax]+=n+m
    path = bfs(ay,ax,fy,fx)
    if path:
        laserattck(path)
    else:
        bombattack(ay,ax,fy,fx)
    time[ay][ax]=t

res =0
for i in range(n):
    res = max(res,max(board[i]))
print(res)

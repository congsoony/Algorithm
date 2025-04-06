import sys
n,m = map(int,input().split())
board = [list(input()) for i in range(n)]
dy,dx=[-1,0,1,0],[0,1,0,-1]
def isrange(y,x):
    return 0<=y and y<n and 0<=x and x<m
flag = True
for i in range(n):
    for j in range(m):
        if board[i][j]=='W':
            for k in range(4):
                ny = i+dy[k]
                nx = j+dx[k]
                if isrange(ny,nx):
                    if board[ny][nx]=='.':
                        board[ny][nx]='D'
                    elif board[ny][nx]=='S':
                        flag=False

if flag:
    print(1)
    for i in range(n):
        for j in range(m):
            print(board[i][j],end='')
        print()
else:
    print(0)


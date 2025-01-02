from collections import deque,defaultdict
n,m,r = map(int,input().split())
board = [list(map(int,input().split())) for i in range(n)]
dq = defaultdict(deque)
pos = defaultdict(deque)
def makedq(t):
    y,x=t,t
    while x<m-t:
        dq[t].append(board[y][x])
        pos[t].append((y,x))
        x+=1
    x-=1
    y+=1
    while y<n-t:
        dq[t].append(board[y][x])
        pos[t].append((y,x))
        y+=1
    y-=1
    x-=1
    while x>=t:
        dq[t].append(board[y][x])
        pos[t].append((y,x))
        x-=1
    x+=1
    y-=1
    while y>t:
        dq[t].append(board[y][x])
        pos[t].append((y,x))
        y-=1

for i in range(min(n,m)//2):
    makedq(i)
for i in range(min(n,m)//2):
    length = len(dq[i])
    for j in range(r%length):
        dq[i].append(dq[i][0])
        dq[i].popleft()
    for j in range(length):
        board[pos[i][j][0]][pos[i][j][1]]=dq[i][j]

for i in range(n):
    for j in range(m):
        print(board[i][j],end=' ')
    print()


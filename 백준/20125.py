import sys
from collections import Counter
input = sys.stdin.readline
n =int(input())
board = [list(input()) for i in range(n)]
y=x=-1
res = [0]*5
for i in range(n):
    for j in range(n):
        if board[i][j]=='*':
            y=i+1
            x=j
            break
    if y!=-1:
        break

for j in range(x-1,-1,-1):
    if board[y][j]!='*':
        break
    res[0]+=1
for j in range(x+1,n):
    if board[y][j]!='*':
        break
    res[1]+=1
y2 = -1
for i in range(y+1,n):
    if board[i][x]!='*':
        y2=i
        break
    res[2]+=1
for i in range(y2,n):
    if board[i][x-1]!='*':
        break
    res[3]+=1
for i in range(y2,n):
    if board[i][x+1]!='*':
        break
    res[4]+=1
print(y+1,x+1)
for i in range(5):
    print(res[i],end=' ')
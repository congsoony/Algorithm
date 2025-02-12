import sys
input =sys.stdin.readline
n= int(input())
l = [list(map(int,input().split())) for i in range(n)]
l.sort()
s = sum(t[1] for t in l)+1
t=0
for i in range(n):
    t+=l[i][1]
    if s//2<=t:
        print(l[i][0])
        break


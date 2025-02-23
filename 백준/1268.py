from collections import defaultdict
import sys
input =sys.stdin.readline
n=int(input())
num=[0]*n
l = [list(map(int,input().split())) for i in range(n)]

d = defaultdict(lambda : defaultdict(list))

for i in range(n):
    for j in range(5):
        d[j][l[i][j]].append(i)

s=[set() for i in range(n)]
for i in range(n):
    for j in range(i+1,n):
        for k in range(5):
            if l[i][k] == l[j][k]:
                s[i].add(j)
                s[j].add(i)
_max = max(len(i) for i in s)
for i in range(n):
    if len(s[i])==_max:
        print(i+1)
        break
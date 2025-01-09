from collections import defaultdict
import sys
sys.setrecursionlimit(3000000)
input = sys.stdin.readline

n = int(input())
l =defaultdict(list)
parent = [0]*(n+1)
for i in range(1,n+1):
    a,b,c = map(int,input().split())
    l[a].append(b)
    l[a].append(c)
    parent[b]=parent[c]=a
last = 0
def dfs(cur):
    global last
    if l[cur][0]!=-1:
        dfs(l[cur][0])
    last = cur
    if l[cur][1]!=-1:
        dfs(l[cur][1])
dfs(1)
cnt = 0
flag = 1
def dfs2(cur):
    global last,flag,cnt
    if l[cur][0]!=-1:
        cnt+=1
        dfs2(l[cur][0])
    if l[cur][1]!=-1:
        cnt+=1
        dfs2(l[cur][1])
    if cur ==last:
        flag = 0
    if flag:
        cnt+=1
dfs2(1)
print(cnt)
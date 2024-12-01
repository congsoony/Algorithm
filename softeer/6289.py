from collections import deque
n,m = map(int,input().split())
val = list(map(int,input().split()))
l = [1]*n
for i in range(m):
    a,b =map(int,input().split())
    l[a-1]&=val[a-1]>val[b-1]
    l[b-1]&=val[b-1]>val[a-1]
print(sum(l))
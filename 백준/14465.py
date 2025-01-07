import sys
input=sys.stdin.readline
n,k,b = map(int,input().split())
l = [0]*(n*2+1)
for i in range(b):
    t = int(input())
    l[t]+=1
res = int (1e9)
for i in range(1,2*n+1):
    l[i]+=l[i-1]
for i in range(k+1,n+1):
    res = min(res,l[i]-l[i-k])
print(res)
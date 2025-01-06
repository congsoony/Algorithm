import sys
input=sys.stdin.readline
n,x= map(int,input().split())
l = [0]+list(map(int,input().split()))
for i in range(n):l[i+1]+=l[i]
res = 0
cnt = 0
for i in range(x,n+1):
    res = max(res , l[i]-l[i-x])
for i in range(x,n+1):
    cnt += 1 if l[i]-l[i-x]==res else 0
if res ==0:
    print('SAD')
else:
    print(res)
    print(cnt)
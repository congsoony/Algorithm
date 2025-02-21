from bisect import bisect_left, bisect_right
n,score,p = map(int,input().split())
l=[]
if n>0:
    l = list(map(int,input().split()))

if n==0:
    print(1)
    exit(0)
if n==p and l[-1]>=score:
    print(-1)
    exit(0)

for i in range(n):l[i]=-l[i]


e = bisect_left(l,-score)+1
print(e if e<=p else -1)

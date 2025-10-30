import math
n, m = map(int, input().split())
segments = [tuple(map(int, input().split())) for _ in range(m)]

l,r = 1,int(1e20)
res = int(1e20)
while l<=r:
    mid = (l+r)//2
    cnt = 0 
    for s in segments:
        cnt += math.ceil((s[1]-s[0]+1)/mid)
    if cnt<=n:
        r=mid-1
        res = min(res,mid)
    else:
        l= mid+1
print(res)
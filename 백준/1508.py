import sys
input =sys.stdin.readline
n,m,k = map(int,input().split())
v= list(map(int,input().split()))
l,r =0,v[-1]-v[0]
_max =0
while l<=r:
    mid =(l+r)//2
    cnt =1
    before =  v[0]
    for i in range(1,k):
        if mid<=(v[i]-before):
            cnt+=1
            before=v[i]
    if cnt>=m:
        _max = max(mid,_max)
        l = mid+1
    else:
        r= mid-1
res =['1']
before = v[0]
m-=1
for i in range(1,k):
    if v[i]-before>=_max and m>0:
        res+=['1']
        m-=1
        before=v[i]
    else:
        res+=['0']
print(''.join(res))
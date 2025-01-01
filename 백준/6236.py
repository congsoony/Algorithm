from bisect import bisect_left
n,m=map(int,input().split())
v = [int(input()) for i in range(n)]

l,r =0,int(1e15)
res = int(1e15)
while l<=r:
    mid = (l+r)//2
    cnt = 0
    money = 0
    flag = 1
    for i in range(n):
        if money>=v[i]:
            money-=v[i]
        else:
            money = mid
            cnt+=1
            if money <v[i]:
                flag=0
                break
            money-=v[i]

    if cnt<=m and flag:
        res = min(res,mid)
        r=mid-1
    else:
        l=mid+1
print(res)

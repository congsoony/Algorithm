n = int(input())
k = int(input())

# Please write your code here.

l =1
r=n*n
res = n*n
while l<=r:
    mid = (l+r)//2
    cnt = 0
    for i in range(1,n+1):
        cnt+=min(mid//i,n)
    if cnt>=k:
        res = min(res,mid)
        r=mid-1
    else:
        l=mid+1
print(res)
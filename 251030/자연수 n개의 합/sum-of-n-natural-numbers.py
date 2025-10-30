s = int(input())

l,r = 1,s

res = 0 

while l<=r:
    mid = (l+r)//2
    t = (mid*(mid+1))//2
    if(t<=s):
        l=mid+1
        res = max(res,mid)
    else:
        r = mid-1
print(res)
from bisect import bisect_left
n=int(input())
l = list(map(int,input().split()))
res = [float('-inf')]
for val in l:
    if res[-1]<val:
        res.append(val)
    else:
        idx = bisect_left(res,val)
        res[idx]=val
print(len(res)-1)
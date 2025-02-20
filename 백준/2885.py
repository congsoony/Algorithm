import math
n=int(input())
res = 1
while res<n:
    res<<=1
cnt =0
t = res
while n>0:
    if n>=t:
        n-=t
    else:
        t>>=1
        cnt+=1
print(res,cnt)

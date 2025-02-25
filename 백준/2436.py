import math

def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
n,m = map(int,input().split())
i=1
l=[]
while i*i<=m:
    if m%i==0:
        l.append(i)
        l.append(m//i)
    i+=1
l.sort()
res=(l[1],l[1]) #수가 같을경우예방 
Min = int(1e15)
for i in range(len(l)-1):
    for j in range(i+1,len(l)):
        g = gcd(l[i],l[j])
        lc = (l[i]*l[j])//g
        if g==n and lc==m:
            if l[i]+l[j]<Min:
                Min= l[i]+l[j]
                res=(l[i],l[j])
print(res[0],res[1])

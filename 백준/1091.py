n =int(input())
p = list(map(int,input().split()))
s = list(map(int,input().split()))
l = [i%3 for i in range(n)]

cnt=0
check =set()
check.add(tuple(l))
while l!=p:
    temp = l[:]
    for i in range(n):
        l[i]=temp[s[i]]
    cnt+=1
    if tuple(l) in check:
        break
    check.add(tuple(l))
if l==p:
    print(cnt)
else:
    print(-1)
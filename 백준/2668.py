n = int(input())
l = [0] + [int(input()) for i in range(n)]
check = [0]*(n+1)
s = set()
v = []
def dfs(cur,root):
    global n,l,check,v,s
    v.append(cur)
    next = l[cur]
    if check[next]==0:
        check[next]=1
        dfs(next,root)
        check[next]=0
    elif next in v:
        s.update(v[v.index(next):])
    v.pop()


for i in range(1,n):
    if i not in s:
        check[i]=1
        dfs(i,i)
        check[i]=0
s = list(s)
print(len(s))
s.sort()
for i in s: print(i)
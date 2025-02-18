n,m = map(int,input().split())
k = int(input())
col,row=[],[]
for i in range(k):
    a,b = map(int,input().split())
    if a==0:
        row.append(b)
    else:
        col.append(b)
col+=[0,n]
row+=[0,m]

row.sort()
col.sort()
res = 0
for i in range(len(row)-1):
    for j in range(len(col)-1):
        res = max(res,(row[i+1]-row[i])*(col[j+1]-col[j]))
print(res)
n = int(input())
l =[input() for i in range(n)]
res = []
for i in range(n):
    if(l[i].count('.')==0):
        res.append([int(l[i]),-1,l[i]])
    else:
        res.append(list(map(int,l[i].split('.'))) + [l[i]])

res.sort(key=lambda x:(x[0],x[1]))
for i in range(n):
    print(res[i][2])
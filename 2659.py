s = set()
for i in range(1,10):
    for j in range(1,10):
        for k in range(1,10):
            for l in range(1,10):
                val = min(i*1000+j*100+k*10+l,j*1000+k*100+l*10+i,k*1000+l*100+i*10+j,l*1000+i*100+j*10+k)
                s.add(val)
v = list(s)
v.sort()
a,b,c,d = map(int ,input().split())
l =[a,b,c,d]
t=[]
for i in range(4):
    t.append(l[0]*1000+l[1]*100+l[2]*10+l[3])
    l.insert(0,l[-1])
    l.pop()
t.sort()
print(v.index(t[0])+1)
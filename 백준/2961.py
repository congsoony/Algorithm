from itertools import combinations

n = int(input())
l = [list(map(int,input().split()))for i in range(n)]
res = int(1e15)
for i in range(1,1<<n):#0부터 시작하면 아무것도 선택하는 경우도 있는걸 배제해야함 1부터해야 무언가 한개이상 선택
    sourness = 1 #신맛
    bittertaste = 0 #쓴맛
    for j in range(n):
        if i&(1<<j):
            sourness*=l[j][0]
            bittertaste+=l[j][1]
    res = min(res,abs(sourness-bittertaste))
print(res)   

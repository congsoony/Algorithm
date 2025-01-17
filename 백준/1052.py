import sys
n,k = map(int,input().split())
res = 0
while bin(n).count('1')>k:
    res+= n&-n
    n+= n&-n
print(res)
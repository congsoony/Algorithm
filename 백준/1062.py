from itertools import combinations
import sys
#sys.stdin = open("input.txt","r")
n,k = map(int,input().split())
l = [list(input()) for i in range(n)]
s = set(list('antatica'))
if k<5:
    print(0)
    sys.exit(0)
alpha=[]
k-=5
l2 = []
for i in range(n):
    bit = 0
    for j in range(len(l[i])):
        if l[i][j] not in s:
            bit|=1<<(ord(l[i][j])-ord('a'))
    l2.append(bit)
for i in range(ord('a'),ord('z')+1):
    if chr(i) not in s:
        alpha.append(chr(i))

com = list(combinations(alpha,k))
res = 0
for i in range(len(com)):
    bit = 0
    cnt = 0
    for j in range(k):
        bit|=1<<(ord(com[i][j])-ord('a'))
    for j in range(n):
        if l2[j]&bit == l2[j]:
            cnt+=1
    res =max(res,cnt)
print(res)
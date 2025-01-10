from collections import defaultdict
#import sys
#sys.stdin = open("input.txt","r")
Test = int(input())
for test in range(1,Test+1):

    t = list(map(int,input().split()))
    n = t.pop(0)
    l = [[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            l[i][j]=t[i*n+j]
            if i!=j and l[i][j]==0:
                l[i][j]=int(1e9)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                l[i][j]=min(l[i][j],l[i][k]+l[k][j])
    res = int(1e9)
    for i in range(n):
        sum = 0
        for j in range(n):
            if l[i][j]!=int(1e9):
                sum+=l[i][j]
        res = min(res,sum)
    print('#{} {}'.format(test,res))   

        
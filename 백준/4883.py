import sys
input =sys.stdin.readline
num=1
while True:
    n = int(input())
    if n==0:
        break
    dp = [[int(1e12) for i in range(5)]for j in range(n)]
    l = [[int(1e12) for i in range(5)]for j in range(n)]
    for i in range(n):
        l2 = list(map(int,input().split()))
        for j in range(3):
            l[i][j+1]=l2[j]
    dp[0][2]=l[0][2]
    dp[0][3]=l[0][2]+l[0][3]

    for i in range(1,n):
        for j in range(1,4):
            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1],dp[i][j-1])+l[i][j]
    print('%d. %d'%(num,dp[n-1][2]))
    num+=1
    
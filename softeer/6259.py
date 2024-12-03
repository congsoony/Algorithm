import sys
input = sys.stdin.readline
n,m,k = map(int,input().split())
l = list(map(int,input().split()))
l2 = list(map(int,input().split()))
dp = [[0]*(m+1) for i in range(n+1)]
res = 0
for i in range(1,n+1):
    for j in range(1,m+1):
        if l[i-1]==l2[j-1]:
            dp[i][j]=dp[i-1][j-1]+1
            res = max(res,dp[i][j])
print(res)
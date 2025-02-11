n,k = map(int,input().split())
l = [int(input()) for i in range(n)]
l.sort()
dp=[int(1e9)]*(k+1)
dp[0]=0
for j in range(k+1):
    for i in range(n):
        if j-l[i]>=0:
            dp[j]=min(dp[j],dp[j-l[i]]+1)
print(dp[k] if dp[k]!=int(1e9) else -1)
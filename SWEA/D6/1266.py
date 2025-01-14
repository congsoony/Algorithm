from collections import defaultdict
# import sys
# sys.stdin = open("input.txt","r")
Test = int(input())
l = [0,1,4,6,8,9,10,12,14,15,16,18]
dp=[[1]*30 for i in range(30)]
for i in range(2,30):
    for j in range(1,i):
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j]

for test in range(1,Test+1):
    sum = 0
    sum2 = 0
    a,b= map(int,input().split())
    a/=100
    b/=100
    for i in l:
        sum2+=dp[18][i]*(a**i)*((1-a)**(18-i))
        sum+=dp[18][i]*(b**i)*((1-b)**(18-i))
    print('#%d %.6f'%(test,1-sum*sum2))




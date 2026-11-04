#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int dp[104][10][1024]={0};
    for(int i =1;i<=9;i++)dp[1][i][1<<i]=1;
    int mod = 1e4+7;
    for(int i =2;i<=n;i++){
        for(int j =0;j<10;j++){
            for(int k =0;k<1024;k++){
                if(j>0)
                    dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k])%mod;
                if(j<9)
                    dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j+1][k])%mod;
            }
        }
    }
    int res = 0;
    for(int i=0;i<=9;i++){
        res = (res+dp[n][i][1023])%mod;
    }
    cout<<res<<"\n";
}
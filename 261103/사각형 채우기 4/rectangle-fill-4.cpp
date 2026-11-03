#include <iostream>
using namespace std;

int main() {
    int n;
    int mod = 10007;
    cin>>n;
    int dp[1005]={1,0,3};
    for(int i =3;i<=n;i++){
        dp[i]=(dp[i-2]*3)%mod;
        for(int j =4;j<=i;j+=2){
            dp[i] = (dp[i] + dp[i-j]*2)%mod;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
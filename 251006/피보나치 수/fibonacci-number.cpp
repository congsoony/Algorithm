#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    int dp[N+10]={0,1,1};
    for(int i =3;i<=N;i++)dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[N]<<"\n";

    return 0;
}

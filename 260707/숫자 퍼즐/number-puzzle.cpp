#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
ll dp[11][201][201];

ll dfs(int idx,int sum,int last){
    if(idx>=n){
        return sum==0?1:0;
    }
    if(dp[idx][sum][last]!=-1)
        return dp[idx][sum][last];
    ll cnt =0;
    for(int i =last;i<=sum;i++){
        cnt+=dfs(idx+1,sum-i,i);
    }
    return dp[idx][sum][last]=cnt;
}
void solve(int idx,int sum,int last,ll k){
    if(idx>=n)return;

    for(int i = last;i<=sum;i++){
        ll cnt = dfs(idx+1,sum-i,i);
        if(k<=cnt){
            cout<<i<<" ";
            solve(idx+1,sum-i,i,k);
            break;
        }
        else{
            k-=cnt;
        }
    }
}
int main() {
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));

    solve(0,m,1,k);
    cout<<endl;

}
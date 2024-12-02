#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<ll> v[2],m[2],dp[2];
void input(){
    cin>>n;
    v[0]=v[1]=m[0]=m[1]=vector<ll>(n);
    for(int i =0;i<n-1;i++){
        cin>>v[0][i]>>v[1][i]>>m[0][i]>>m[1][i];
    }
    cin>>v[0][n-1]>>v[1][n-1];
}
ll dfs(int cur,int pos){
    if(cur>=n)return 0;
    ll &cache =dp[pos][cur];
    if(cache !=1e9)return cache;
    return cache = min(dfs(cur+1,pos)+v[pos][cur],dfs(cur+1,!pos)+v[pos][cur]+m[pos][cur]);
}
void solve(){
    dp[0]=dp[1]=vector<ll>(n,1e9);
    cout<<min(dfs(0,1),dfs(0,0))<<"\n";

}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    
}
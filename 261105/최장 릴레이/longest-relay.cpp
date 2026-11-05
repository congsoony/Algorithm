#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> v;
int dp[20][1<<15][21];
int dfs(int cur,int bit,int before){
    if(bit==(1<<n)-1)return 0;
    int &cache =dp[cur][bit][before];
    if(cache!=-1)return cache;
    cache = 0;
    for(int i =0;i<n;i++){
        if(v[cur][i]>before&&!(bit&(1<<i)))
            cache = max(cache,dfs(i,bit|(1<<i),v[cur][i]) +1);
    }
    return cache;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    cin>>n;
    v= vector<vector<int>>(n,vector<int>(n));
    memset(dp,-1,sizeof(dp));
    for(int i =0;i<n;i++)for(int j=0;j<n;j++)cin>>v[i][j];
    cout<<dfs(0,1,0)+1<<"\n";
    
}
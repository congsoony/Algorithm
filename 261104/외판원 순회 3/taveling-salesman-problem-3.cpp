#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>> dp,v;
int dfs(int cur=0,int bit=1){
    if(__builtin_popcount(bit)>=k+1){
        return v[cur][0];
    }
    int &cache = dp[cur][bit];
    if(cache!=1e9)return cache;
    for(int i =0;i<n;i++){
        if(v[cur][i]==0)continue;
        if(bit&(1<<i))continue;
        cache = min(cache,dfs(i,bit|1<<i) + v[cur][i]);
    }
    return cache;
}
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>k;
    v= vector<vector<int>>(n,vector<int>(n));
    dp = vector<vector<int>>(n,vector<int>(1<<n,1e9));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<dfs()<<"\n";
}
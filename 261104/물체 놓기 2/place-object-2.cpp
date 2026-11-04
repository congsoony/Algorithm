#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> v;
vector<int> cost,dp;
int dfs(int bit){
    if(__builtin_popcount(bit)>=m){
        return 0;
    }
    int &cache = dp[bit];
    if(cache!=1e8)return cache;
    for(int i =0;i<n;i++){
        if((bit&(1<<i)))continue;
        int mincost = cost[i];
        for(int j =0;j<n;j++){
            if(bit&(1<<j)){
                mincost = min(mincost,v[j][i]);
            }
        }
        int nextbit = bit|(1<<i);
        cache = min(cache,mincost+dfs(nextbit));
    }
    return cache;
}
int main() {
    
    cin>>n>>m;
    dp =vector<int>((1<<n),1e8);
    v =vector<vector<int>>(n,vector<int>(n));
    cost =vector<int>(n);
    for(int i =0;i<n;i++)cin>>cost[i];
    
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<dfs(0)<<"\n";
}
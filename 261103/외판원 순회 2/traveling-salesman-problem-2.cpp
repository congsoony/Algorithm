#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> dp,v;
int dfs(int cur=0,int check=1){
    if(check ==(1<<n) -1){
        if(v[cur][0]==0)return 1e8;
        return v[cur][0];
    }
    int &cache = dp[cur][check];
    if(cache!=1e8)return cache;
    for(int i =0;i<n;i++){
        if(v[cur][i]==0)continue;
        if((check &(1<<i)))continue;
        cache = min(cache,dfs(i,check | (1<<i)) + v[cur][i]);
    }
    return cache;
}
int main() {

    cin>>n;
    dp =vector<vector<int>>(n,vector<int>((1<<n),1e8));
    v =vector<vector<int>>(n,vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<dfs(0)<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> dp,v;
int dfs(int cur=0,int check=(1<<n)-1){
    if(cur>=n){
        return 0;
    }
    int &cache = dp[cur][check];
    if(cache!=-1)return cache;
    int tempcheck = check;
    while(tempcheck>0){
        int bit =  (tempcheck& -tempcheck);
        int next = __builtin_ctz(bit);
        tempcheck -=bit;
        cache = max(cache,dfs(cur+1,check^bit) + v[cur][next]);
    }
    return cache;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin>>n;
    dp =vector<vector<int>>(n,vector<int>((1<<n),-1));
    v =vector<vector<int>>(n,vector<int>(n));
    
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<dfs(0)<<"\n";
}
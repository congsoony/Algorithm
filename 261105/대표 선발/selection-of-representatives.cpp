#include<bits/stdc++.h>
using namespace std;
int n;
int Max = 0;
vector<vector<int>> v,dp;
int mod = 10007;
int dfs(int p,int bit){
    if(bit==(1<<n)-1)return 1;
    if(p>Max)return 0;
    int &cache = dp[p][bit];
    if(cache!=-1)return cache;
    cache = dfs(p+1,bit);
    for(int num:v[p]){
        if(bit&(1<<num))continue;
        cache = (cache + dfs(p+1,bit|(1<<num)))%mod;
    }
    return cache%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    cin>>n;
    v= vector<vector<int>>(101);
    
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j =0;j<m;j++){
            int a;
            cin>>a;
            v[a].push_back(i);
            Max = max(a,Max);
        }
    }
    dp =vector<vector<int>>(Max+1,vector<int>(1<<n,-1));
    cout<<dfs(1,0)<<"\n";

}
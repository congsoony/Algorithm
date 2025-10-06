#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int n,m;
int dfs(int cur=0,int p=0){
    if(p<0 || p>(m))return 0;
    if(cur>=n)return p==0;
    int &cache = dp[cur][p];
    if(cache!=-1)return cache;
    int res = dfs(cur+1,p+1)+dfs(cur+1,p-1);
    return cache =res;
}

int main() {
    cin>>n;
    m = n;
    n*=2;
    dp = vector<vector<int>>(n,vector<int>(m+1,-1));
    cout<<dfs()<<"\n";
}
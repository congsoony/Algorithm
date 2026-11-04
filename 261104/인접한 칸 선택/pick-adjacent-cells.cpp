#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> v;
vector<vector<vector<int>>> dp;

int dfs(int y=0,int x=0,int bit=0){
    if(x>=m)return dfs(y+1,0,bit);
    if(y>=n)return 0;
    int &cache = dp[y][x][bit];
    if(cache!=-1e8)return cache;
    
    int nextbit = (bit<<1) & ((1<<m)-1);
    cache = dfs(y,x+1,nextbit);
    if(v[y][x])return cache;
    if(y>0 && (bit &(1<<(m-1))))return cache;
    if(x>0 && (bit & 1))return cache;
    return cache = max(cache , dfs(y,x+1,nextbit|1)+1);
}
int main() {
//freopen("input.txt","r",stdin);
    cin>>n>>m;
    v= vector<vector<int>>(n,vector<int>(m));
    dp =vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(1<<m,-1e8)));

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<dfs()<<"\n";
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int num=1;
vector<vector<ll>> dp,v;
int dy[4]={0,1,1,1};
int dx[4]={1,1,0,-1};
void input(){
    cin>>n;
    dp = v = vector<vector<ll>>(n,vector<ll>(3,1e15));
    for(int i =0;i<n;i++){
        for(int j =0;j<3;j++){
            cin>>v[i][j];
        }
    }
}
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<3;
}
ll dfs(int y=0,int x=1){
    if(y==n-1){
        return x?x==1?v[y][x]:1e15:v[y][x]+v[y][x+1];
    }
    if(!isrange(y,x)) return 1e15;
    ll &cache = dp[y][x];
    if(cache!=1e15)return cache;

    for(int i =0;i<4;i++){
        cache = min(cache,dfs(y+dy[i],x+dx[i])+v[y][x]);
    }

    return cache;

}
void solve(){
    cout<<num++<<". "<<dfs()<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    while(1){
        input();
        if(n==0)break;
        solve();
    }

}
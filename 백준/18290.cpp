#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>board,check;
ll n,m,k;
ll res = -1e15;
void input(){
    cin>>n>>m>>k;
    check= board = vector<vector<ll>>(n,vector<ll>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
}
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}


void dfs(int cnt=0,int sel=k,ll sum=0){
    if(sel==0){
        res= max(res,sum);
        return;
    }
    if(cnt>=n*m){
        return;
    }
    int y= cnt/m;
    int x= cnt%m;
    if(cnt<m){
        check[y][x]=1;
        if(x==m-1)
            dfs(cnt+1,sel-1,sum+board[y][x]);
        else
            dfs(cnt+2,sel-1,sum+board[y][x]);
        check[y][x]=0;
    }
    else{
        if(!check[y-1][x]){    
            check[y][x]=1;
            if(x==m-1)
                dfs(cnt+1,sel-1,sum+board[y][x]);
            else
                dfs(cnt+2,sel-1,sum+board[y][x]);
            check[y][x]=0;
        }
    }
    dfs(cnt+1,sel,sum);
}
void solve(){   
    dfs();
    cout<<res<<"\n";    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    
}

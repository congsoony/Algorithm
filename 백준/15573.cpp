#include <bits/stdc++.h>
using namespace std;
int board[1003][1003];
int check[1003][1003];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m,k;
void input(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
        }
    }
}
bool isrange(int y,int x){
    return 0<=y&&y<=n && 0<=x&&x<=m+1;
}
int bfs(int d,int num){
    check[0][0]=num;
    queue<pair<int,int>> q;
    q.push({0,0});
    int cnt=0;
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        cnt+=board[y][x]?1:0;
        if (cnt>=k)return 1;
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(isrange(ny,nx)&& board[ny][nx]<=d &&check[ny][nx]!=num){
                check[ny][nx]=num;
                q.push({ny,nx});
            }
        }
    }
    return 0;
}
void solve(){
    int l=1,r=1e8;
    int res = 1e8;
    int num=1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(bfs(mid,num++)){
            res = min(res,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve();

 
}

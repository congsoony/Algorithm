#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,b;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<vector<ll>> board;
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<n;
}
ll dijkstra(int y1,int x1){
    vector<vector<ll>> dist(n,vector<ll>(n,1e15));
    priority_queue<tuple<ll,ll,ll>> pq;
    dist[y1][x1]=0;
    pq.push({0,y1,x1});
    while(!pq.empty()){
        ll cost,y,x;
        tie(cost,y,x)=pq.top();
        pq.pop();
        cost = -cost;
        if(dist[y][x]<cost)continue;
        for(int i =0;i<4;i++){
            int ny= y+dy[i];
            int nx= x+dx[i];
            if(isrange(ny,nx)){
                ll ncost = (board[y][x]==board[ny][nx]?a:b) + cost;
                if(dist[ny][nx]>ncost){
                    pq.push({-ncost,ny,nx});
                    dist[ny][nx]=ncost;
                }
            }
        }
    }
    ll res = 0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            res = max(dist[i][j],res);
        }
    }
    return res;
}
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>a>>b;
    char c;
    board = vector<vector<ll>>(n,vector<ll>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>c;
            board[i][j]=c=='(';
        }
    }
    ll res = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            res = max(res,dijkstra(i,j));
        }
    }
    cout<<res<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
int board[100][100];
int color[100][100];
int n,m;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<pair<int,int>> v;
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}
int bfs(int dis){

    vector<vector<int>>dist(n,vector<int>(m,1e9));
    queue<pair<int,int>> q;
    q.push({v[0].first,v[0].second});
    dist[v[0].first][v[0].second]=0;
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        for(int i =0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(isrange(ny,nx)){
                int ncost = abs(board[y][x]-board[ny][nx]);
                if(dist[ny][nx]>ncost&&ncost<=dis){
                    q.push({ny,nx});
                    dist[ny][nx]=ncost;
                }
            }
        }
    }

    for(auto[y,x]:v){
        if(dist[y][x]==1e9)return 0;
    }
    return 1;
}
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>board[i][j];
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>color[i][j];
            if(color[i][j])
                v.push_back({i,j});
        }
    }
    
    int l=1,r=1e9;
    int res = 1e9;
    while(l<=r){
        int mid = (l+r)/2;
        if(bfs(mid)){
            r = mid-1;
            res = min(res,mid);
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<"\n";
}
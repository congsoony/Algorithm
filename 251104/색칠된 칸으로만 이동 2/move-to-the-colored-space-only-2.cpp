#include<bits/stdc++.h>
using namespace std;
int board[100][100];
int color[100][100];
int n,m;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}
int bfs(int y,int x,int y2,int x2,int dis){

    vector<vector<int>>dist(n,vector<int>(m,1e9));
    queue<pair<int,int>> q;
    q.push({y,x});
    dist[y][x]=0;
    while(!q.empty()){
        tie(y,x)=q.front();
        q.pop();
        if(y==y2&&x==x2)return 1;
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
    return 0;
}
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>board[i][j];
        }
    }
    vector<pair<int,int>> v;
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
        int size = v.size();
        int flag = 1;
        for(int i =0;i<size-1;i++){
            for(int j =i+1;j<size;j++){
                flag&=bfs(v[i].first,v[i].second,v[j].first,v[j].second,mid);

                if(flag==0)break;
            }
            if(flag==0)break;
        }
        if(flag){
            r = mid-1;
            res = min(res,mid);
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<"\n";
}
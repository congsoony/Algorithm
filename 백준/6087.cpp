#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> board;
vector<pair<int,int>> pos;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
void input(){
    cin>>m>>n;
    board = vector<vector<int>>(n,vector<int>(m));
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if(c=='*')
                board[i][j]=1;
            else if(c=='C'){
                pos.push_back({i,j});
            }          
        }
    }
}

bool isrange(int y,int x){
    return 0<=y&&y<n &&0<=x&&x<m;
}

void solve(){
    vector<vector<int>> dist[4];
    dist[0]=dist[1]=dist[2]=dist[3]= vector<vector<int>>(n,vector<int>(m,1e9));
    priority_queue<tuple<int,int,int,int>> pq;
    
    for(int i =0;i<4;i++){
        dist[i][pos[0].first][pos[0].second]=0;
        pq.push({0,i,pos[0].first,pos[0].second});
    }
    while(!pq.empty()){
        int cnt,dir,y,x;
        tie(cnt,dir,y,x)=pq.top();
        pq.pop();
        cnt= -cnt;
        for(int r : {0,1,3}){
            int ncnt = cnt+(r>0);
            int ndir = (dir+r)%4;
            int ny=y+dy[ndir];
            int nx= x+dx[ndir];
            if(isrange(ny,nx) && dist[ndir][ny][nx]>ncnt && board[ny][nx]==0){
                pq.push({-ncnt,ndir,ny,nx});
                dist[ndir][ny][nx]=ncnt;
            }
        }
    }
    int res = 1e9;
    for(int i =0;i<4;i++){
        res = min(res,dist[i][pos[1].first][pos[1].second]);
    }
    cout<<res<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve();
}
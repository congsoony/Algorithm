#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector<vector<ll>>board,check;
int dy[5]={-1,0,1,0,0};
int dx[5]={0,1,0,-1,0};
int ressize=1e8;
string res ="";
vector<string> ts = {"^",">", "v","<"  };
int idr = 0;
int ry,rx;
int cnt = 0;
int sy,sx;
string rts;
void input(){
    cin>>n>>m;
    check = board = vector<vector<ll>>(n,vector<ll>(m));
    char c;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>c;
            if(c=='#'){
                board[i][j]=1;
                cnt++;
            }
        }
    }
    cnt--;
}
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}
int finddir(int y,int x,int ny,int nx){
    for(int i=0;i<4;i++){
        int ny2= y+dy[i]*2;
        int nx2= x+dx[i]*2;
        if(ny2==ny && nx2==nx)
            return i;
    }
    return -1;
}
void dfs(int y,int x,int dir,string &s,int h=0){
    if(h>=cnt/2){
        if(s.size()<ressize){
            res = s;
            ressize= res.size();
            rts = ts[idr];
            tie(sy,sx)={ry,rx};
        }
        return;
    }
    for(auto i :{1,3}){
        int ny=y+dy[(dir+i)%4];
        int nx=x+dx[(dir+i)%4];
        int ny2=ny+dy[(dir+i)%4];
        int nx2=nx+dx[(dir+i)%4];
        if(isrange(ny,nx)&&isrange(ny2,nx2)&&!check[ny][nx]&&!check[ny2][nx2]){
            if(board[ny][nx]&&board[ny2][nx2]){
                s+=(i==1?"R":"L");
                s+="A";
                dfs(ny2,nx2,(dir+i)%4,s,h+1);
                s.pop_back();
                s.pop_back();
            }
        }
    }
    int ny=y+dy[dir];
    int nx=x+dx[dir];
    int ny2=ny+dy[dir];
    int nx2=nx+dx[dir];
    if(isrange(ny,nx)&&isrange(ny2,nx2)&&!check[ny][nx]&&!check[ny2][nx2]){
        if(board[ny][nx]&&board[ny2][nx2]){
            s+="A";
            dfs(ny2,nx2,dir,s,h+1);
            s.pop_back();
        }
    }
}

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                if(board[i][j]){
                    tie(ry,rx)={i,j};
                    idr = k;
                    string s="";
                    check[i][j]=1;
                    dfs(i,j,k,s);
                    check[i][j]=0;
                }
            }
        }
    }
    cout<<sy+1<<" "<<sx+1<<"\n";
    cout<<rts<<"\n";
    cout<<res<<"\n";
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    //freopen("input.txt","r",stdin);
    input();
    solve();
    
}
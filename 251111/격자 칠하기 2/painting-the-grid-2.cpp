#include <bits/stdc++.h>
using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n;
vector<vector<int>> board,check;
int num = 0;
int isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<n;
}

int bfs(int y,int x,int d){
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({y,x});
    check[y][x]=num;
    while(!q.empty()){
        tie(y,x)=q.front();
        q.pop();
        cnt++;
        for(int i =0;i<4;i++){
            int ny=y+dy[i];
            int nx= x+dx[i];
            if(isrange(ny,nx)&&check[ny][nx]!=num && abs(board[ny][nx]-board[y][x])<=d){
                q.push({ny,nx});
                check[ny][nx]=num;
            }
        }
    }
    return cnt;
}
int possible(int d){
    num++;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            if(check[i][j]>=num)continue;
            if(bfs(i,j,d)>=(n*n+1)/2)
                return 1;
        }
    }
    return 0;
}


int main() {
    cin>>n;
    check = board=vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    int l = 0,r = 1e6;
    int res =1e9;
    while(l<=r){
        int mid = (l+r)/2;
        if(possible(mid)){
            res = min(res,mid);
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<res<<"\n";

}
#include<bits/stdc++.h>
using namespace std;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> board;
int n,m;
int main() {
    cin>>n>>m;
    board = vector<vector<int>>(n+2,vector<int>(m+2));
    int res = 0;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            cin>>board[i][j];
        }
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            for(int k =0;k<4;k++){
                int ny = i+dy[k];
                int nx =j+dx[k];
                int ny2 = i+dy[(k+1)%4];
                int nx2 = j+dx[(k+1)%4];
                int ny3 = i+dy[(k+2)%4];
                int nx3 = j+dx[(k+2)%4];
                res = max({res,board[i][j] + board[ny][nx] + board[ny2][nx2] , board[i][j] + board[ny][nx] + board[ny3][nx3]});
            }
        }
    }
    cout<<res<<"\n";
}
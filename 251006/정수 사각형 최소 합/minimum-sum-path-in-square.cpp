#include<bits/stdc++.h>
using namespace std;

int n;
int grid[100][100];
vector<vector<int>> dp;
int dfs(int y,int x){
    if(y>=n || x<0)return 1e9;
    if(y==n-1&&x==0)return grid[y][x];
    int &cache = dp[y][x];
    if(cache!=1e9)return cache;
    return cache = min(dfs(y+1,x),dfs(y,x-1))+grid[y][x];
}
int main() {
    cin >> n;
    dp= vector<vector<int>>(n,vector<int>(n,1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout<<dfs(0,n-1)<<"\n";
    return 0;
}

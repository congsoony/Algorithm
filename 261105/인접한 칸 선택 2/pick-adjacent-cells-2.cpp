#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v,temp;
vector<vector<vector<int>>> dp;
int dfs(int y=0,int x = 0,int bit=0){
    if(y>=n)return 0;
    if(x>=m)return dfs(y+1,0,bit);
    int &cache = dp[y][x][bit];
    if(cache!=-1e8)return cache;
    int nextbit = bit &~(1<<x);
    cache = dfs(y,x+1,nextbit);
    bool flag =true;
    if(y>0&& (bit&(1<<x))){
        flag = false;
    }
    if(x>0&&(bit&1<<(x-1))){
        flag =false;
    }
    if(flag){
        cache =max(cache,dfs(y,x+1,bit|(1<<x)) + v[y][x]);
    }
    return cache;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    cin >> n>>m;

    temp = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp[i][j];
        }
    }
    swap(n,m);
    v = vector<vector<int>>(n, vector<int>(m));
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1 << m, -1e8)));
    for(int i =0,j2=m-1;i<m;i++,j2--){
        for(int j =0,i2=0;j<n;j++,i2++){
            v[i2][j2]=temp[i][j];
        }
    }
    cout << dfs() << "\n";
    return 0;
}
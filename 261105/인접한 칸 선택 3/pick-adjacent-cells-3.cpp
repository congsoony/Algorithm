
#include <bits/stdc++.h>
using namespace std;

int n, m,k;
vector<vector<int>> v,temp;
int dp[10][10][1024][50];
int dfs(int y=0,int x = 0,int bit=0,int cnt=0){
    if(cnt>=k || cnt>=(n*m)/2 +1)return 0;
    if(y>=n)return 0;
    if(x>=m)return dfs(y+1,0,bit,cnt);
    int &cache = dp[y][x][bit][cnt];
    if(cache!=-1)return cache;
    int nextbit = bit &~(1<<x);
    cache = dfs(y,x+1,nextbit,cnt);
    bool flag =true;
    if(y>0&& (bit&(1<<x))){
        flag = false;
    }
    if(x>0&&(bit&1<<(x-1))){
        flag =false;
    }
    if(flag){
        cache =max(cache,dfs(y,x+1,bit|(1<<x),cnt+1) + v[y][x]);
    }
    return cache;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    cin >> n>>m>>k;

    v = vector<vector<int>>(n, vector<int>(m));
    memset(dp,-1,sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
  
    cout << dfs() << "\n";
    return 0;
}
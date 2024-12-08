#include<bits/stdc++.h>
using namespace std;

int n,e,a,b;
vector<vector<int>> v,parent;
vector<int> cnt,depth;

void input(){
    cin>>n>>e>>a>>b;
    depth=cnt =vector<int>(n+1,1);
    v=vector<vector<int>>(n+1);
    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
}

int lca(int x,int y){
    if(depth[x]>depth[y])swap(x,y);
    for(int i=19;i>=0;i--){
        if(depth[y]-depth[x] >=(1<<i))y=parent[i][y];
    }
    if(x==y)return x;

    for(int i=19;i>=0;i--){
        if(parent[i][x]!=parent[i][y]){
            x=parent[i][x];
            y=parent[i][y];
        }

    }
    return parent[0][x];
}
void dfs(int cur,int before=0,int h=0){
    parent[0][cur]=before;
    depth[cur]=h;
    for(int next:v[cur]){
        dfs(next,cur,h+1);
        cnt[cur]+=cnt[next];
    }
}

void solve(){
    parent =vector<vector<int>>(20,vector<int>(n+1));
    dfs(1);
    for(int i=1;i<20;i++){
        for(int j =1;j<=n;j++){
            parent[i][j]=parent[i-1][parent[i-1][j]];
        }
    }
    int node = lca(a,b);
    cout<<node<<" "<<cnt[node]<<"\n";

}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        cout<<"#"<<i<<" ";
        input();
        solve(); 
    }
}
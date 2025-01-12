#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
vector<ll> group,depth;
vector<vector<ll>> parent,maxcost,sumcost;
vector<vector<pair<ll,ll>>>adj;
vector<tuple<ll,ll,ll>> v;
void input(){
    cin>>n>>m;
    ll a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push_back({-c,a,b});
    }
    adj = vector<vector<pair<ll,ll>>>(n+1);
    parent=maxcost=sumcost = vector<vector<ll>>(19,vector<ll>(n+1));
    depth = group =vector<ll>(n+1);
}

int find(int idx){
    if(group[idx]==idx)return idx;
    return group[idx]=find(group[idx]);
}
int merge(int a,int b){
    a =find(a);
    b =find(b);
    if(a==b)return false;
    group[b]=a;
    return true;
}

void dfs(int cur=1,ll total=0,int p=0,int h=0){
    parent[0][cur]=p;
    sumcost[0][cur]=total;
    depth[cur]=h;
    for(int i=0;i<adj[cur].size();i++){
        if(adj[cur][i].first==p)continue;
        ll next,cost;
        tie(next,cost)=adj[cur][i];
        maxcost[0][next]=cost;
        dfs(next,total+cost,cur,h+1);
    }
}

ll lca(ll x,ll y){
    if(depth[x]>depth[y])swap(x,y);
    ll _max = 0;
    for(int i=18;i>=0;i--){
        if(depth[y]-depth[x]>=(1<<i)){
            _max = max(_max,maxcost[i][y]);
            y=parent[i][y];
        }
    }
    if(x==y)return _max;
    for(int i=18;i>=0;i--){
        if(parent[i][x]!=parent[i][y]){
            _max = max({_max,maxcost[i][x],maxcost[i][y]});
            x= parent[i][x];
            y= parent[i][y];
        }
    }
    return max({_max,maxcost[0][x],maxcost[0][y]});

}

void solve(){ 
    
    for(int i=1;i<=n;i++)group[i]=i;
    ll mst = 0;
    priority_queue<tuple<ll,ll,ll>> pq(v.begin(),v.end());
    ll cost,a,b;
    while(!pq.empty()){
        tie(cost,a,b)=pq.top();
        pq.pop();
        if(merge(a,b)){
            mst-=cost;
            adj[a].push_back({b,-cost});
            adj[b].push_back({a,-cost});
        }
    }

    dfs();
    for(int i=1;i<19;i++){
        for(int j =1;j<=n;j++){
            parent[i][j]=parent[i-1][parent[i-1][j]];
            maxcost[i][j]=max(maxcost[i-1][j],maxcost[i-1][parent[i-1][j]]);

        }
    }
    for(int i=0;i<m;i++){
        tie(cost,a,b)=v[i];
        cout<<mst-cost-lca(a,b)<<"\n";
    }


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}

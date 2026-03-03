#include<bits/stdc++.h> 
using namespace std;
#define ll long long
ll n,m;
vector<pair<ll,ll>> v[1001];
ll parent[10001];
set<pair<ll,ll>> check;
vector<ll> dijkstra(ll start){
    vector<ll> dist(n+1,1e9);
    dist[start] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        ll cost = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
        if(dist[cur]<cost) continue;
        for(ll i =0;i<v[cur].size();i++){
            ll next = v[cur][i].first;
            ll nextCost = cost + v[cur][i].second;
            if(check.count({cur,next}))continue;
            if(nextCost<dist[next]){
                dist[next] = nextCost;
                parent[next]=cur;
                pq.push({nextCost,next});
            }
        }
    }
    return dist;
}
int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<pair<ll,ll>> iv;
    for(ll i =0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i =1;i<=n;i++)sort(v[i].begin(),v[i].end());
    
    vector<ll> dist = dijkstra(1);
    ll res = 0;
    ll cur = n;
    while(cur!=1){
        for(int i=v[cur].size()-1;i>=0;i--){
            if(dist[cur]==dist[parent[cur]]+v[cur][i].second){
                check.insert({parent[cur],cur});
                check.insert({cur,parent[cur]});
                cur=parent[cur];
                break;
            }
        }
    }
 
  
    vector<ll> dist2 = dijkstra(1);
    cout<<dist2[n]<<"\n";
}
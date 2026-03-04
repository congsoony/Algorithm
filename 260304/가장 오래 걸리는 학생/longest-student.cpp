#include<bits/stdc++.h> 
using namespace std;
#define ll long long
ll n,m;
vector<pair<ll,ll>> v[100001];
vector<ll> dijkstra(ll start){
    vector<ll> dist(n+1,1e15);
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
            if(nextCost<dist[next]){
                dist[next] = nextCost;
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
    vector<ll> dist = dijkstra(n);
    ll res = 0;
    for(int i=1;i<n;i++){
        res = max(res,dist[i]);
    }
    cout<<res<<"\n";

}
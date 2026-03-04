#include<bits/stdc++.h> 
using namespace std;
#define ll long long
ll n,m;
vector<ll> dijkstra(ll start,vector<pair<ll,ll>> *v){
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
vector<ll> getPath(ll cur,ll end,vector<pair<ll,ll>> *v,vector<ll> &dist){
    vector<ll> path={cur};
    while(cur!=end){
        for(int i =0;i<v[cur].size();i++){
            ll next = v[cur][i].first;
            ll nextCost = v[cur][i].second;
            if(dist[next]+nextCost== dist[cur]){
                path.push_back(next);
                cur = next;
                break;
            }
        }
    }
    reverse(path.begin(),path.end());
    return path;
}
int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<pair<ll,ll>> av[10001],bv[10001],rav[10001],rbv[10001];

    for(ll i =0;i<m;i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        av[a].push_back({b,c});
        bv[a].push_back({b,d});
        rav[b].push_back({a,c});
        rbv[b].push_back({a,d});
    }
    
    vector<ll> dist1 = dijkstra(n,rav);
    vector<ll> dist2 = dijkstra(n,rbv);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    vector<ll>dist(n+1,1e15);
    while(!pq.empty()){
        ll cost = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
        if(dist[cur]<cost) continue;
        for(ll i =0;i<av[cur].size();i++){
            ll next = av[cur][i].first;
            ll ncost1 =av[cur][i].second;
            ll ncost2 =bv[cur][i].second;
            ll dif=0;
            if(dist1[next]+ncost1 != dist1[cur]) dif++;
            if(dist2[next]+ncost2 != dist2[cur]) dif++;
            if(dist[next]>cost+dif){
                dist[next] = cost+dif;
                pq.push({dist[next],next});
            }   
        }
    }
    cout<<dist[n];
}
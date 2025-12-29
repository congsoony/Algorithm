#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<pair<ll,ll>> v[100001];
vector<ll> dijkstra(int start){
    vector<ll> dist(n+1,1e15);
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty()){
        int cost,cur;
        tie(cost,cur)=pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur]<cost)continue;
        for(auto[next,nc]:v[cur]){
            int ncost = nc + cost;
            if(dist[next]>ncost){
                pq.push({-ncost,next});
                dist[next]=ncost;
            }
        }
    }
    return dist;
}
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    ll a,b,c;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        
    }
    cin>>a>>b;
   
    vector<ll> distA = dijkstra(a);
    cout<<distA[b]<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector<pair<ll,ll>> v[100001];
vector<ll> dijkstra(int s1,int s2, int s3){
    vector<ll> dist(n+1,1e15);
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,s1});
    pq.push({0,s2});
    pq.push({0,s3});
    dist[s1]=0;
    dist[s2]=0;
    dist[s3]=0;
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
    ll x,y,z;
    cin>>x>>y>>z;
    ll a,b,c;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        
    }
    cin>>a>>b;
   
    vector<ll> dist = dijkstra(x,y,z);
    ll res = 0;
    for(int i =1;i<=n;i++){
        res = max(res,dist[i]);
    }
    cout<<res<<"\n";
}
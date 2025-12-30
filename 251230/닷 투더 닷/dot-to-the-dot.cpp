#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x;
vector<tuple<ll,ll,ll>> v[1001];
ll dijkstra(ll  c){
    priority_queue<tuple<ll,ll>> pq;
    pq.push({0,1});
    vector<ll>dist(n+1,1e15);
    dist[1]=0;
    while(!pq.empty()){
        ll cost ,cur;
        tie(cost,cur)= pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur]<cost)continue;
        for(auto[next,L,C]:v[cur]){
            if(C<c)continue;
            ll ncost = cost+L;
            if(dist[next]>ncost){
                pq.push({-ncost ,next});
                dist[next]=ncost;
            }
        }
    }
    return dist[n];
}
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>m>>x;
    ll a,b,c,d;
    set<ll> cs;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c>>d;
        v[a].push_back({b,c,d});
        v[b].push_back({a,c,d});
        cs.insert(d);
    }
    
    ll res =1e15;
    for(ll t : cs){
        res = min(dijkstra(t) + x/t,res);
    }
    cout<<res<<"\n";
}
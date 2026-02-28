#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll x,y;
vector<pair<int,ll>> v[100001]; 
vector<ll> dijkstra(ll cur){
    priority_queue<pair<int,int>> pq;
    pq.push({0,cur});
    vector<ll> dist(n+1,1e15);
    dist[cur]=0;
    while(!pq.empty()){
        ll cost;
        tie(cost,cur)=pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur]<cost)continue;
        for(ll i =0;i<v[cur].size();i++){
            ll next = v[cur][i].first;
            ll ncost = v[cur][i].second+cost;
            if(dist[next]> ncost){
                dist[next] = ncost;
                pq.push({-ncost,next});
            }
        }
    }
    return dist;
}
int main(){
    freopen("input.txt","r",stdin);

    cin>>n>>m;
    cin>>x>>y;
    ll a,b,c;
    for(ll i =0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<ll> dist1 = dijkstra(x);
    vector<ll> dist2 = dijkstra(y);
    
    ll res = 1e15;

    for(ll i =1;i<=n;i++){
        if(i== x || i==y)continue;
        if(dist1[y] + dist2[i]== dist1[i]){
            res = min(res,2*dist1[i]);
        }
        else if(dist2[x]+dist1[i]==dist2[i]){
            res = min(res,2*dist2[i]);           
        }
        else{
            res = min(res,dist1[i]*2 + dist2[i]*2);
        }
    }
    cout<<(res==1e15?-1:res)<<"\n";
}
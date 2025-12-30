#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x;
vector<tuple<ll,ll,ll>> v[1001];
int main() {
    cin>>n>>m>>x;
    ll a,b,c,d;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c>>d;
        v[a].push_back({b,c,d});
        v[b].push_back({a,c,d});
    }
    queue<tuple<ll,ll,ll>> q;
    q.push({1,0,1e15});
    vector<ll>dist(n+1,1e15);
    dist[1]=0;

    while(!q.empty()){
        ll cur,sum,minc;
        tie(cur,sum,minc)= q.front();
        q.pop();
        ll cost = sum+minc/x;


        for(auto[next,L,C]:v[cur]){
            ll nextsum  = sum + L;
            ll nextC = min(minc,C);
            ll nextcost = nextsum + x / nextC;
            if(dist[next]>nextcost){
                q.push({next,nextsum,nextC});
                dist[next]=nextcost;
            }
        }
    }
    cout<<dist[n]<<"\n";
}
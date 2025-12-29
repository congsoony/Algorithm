#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> v[100001];
int main() {
    cin>>n>>m;
    int a,b,c;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin>>a>>b;
    vector<int> dist(n+1,2e9);
    priority_queue<pair<int,int>> pq;
    pq.push({0,a});
    dist[a]=0;
    vector<int> path(n+1);
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
                path[next]=cur;
            }
        }
    }
    vector<int> res;
    res.push_back(b);
    cout<<dist[b]<<"\n";
    while(b!=a){
        b=path[b];
        res.push_back(b);
    }
    reverse(res.begin(),res.end());
    
    for(int t:res)cout<<t<<" ";
}
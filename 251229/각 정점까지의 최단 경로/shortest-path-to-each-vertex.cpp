#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int>> v[100001];

int main() {
    cin>>n>>m>>k;
    int a,b,c;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<int> dist(n+1,2e9);
    priority_queue<pair<int,int>> pq;
    pq.push({0,k});
    dist[k]=0;

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
    for(int i =1;i<=n;i++){
        cout<<dist[i]<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> v[1001];
int main(){
    cin>>n>>m;
    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }

    priority_queue<pair<int,int>> pq;
    vector<int> dist(n+1,1e9);
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int cost,cur;
        tie(cost,cur)=pq.top();
        pq.pop();
        cost=-cost;
        if(dist[cur]<cost)continue;
        for(auto[next,nc]:v[cur]){
            int ncost = cost+nc;
            if(dist[next]>ncost){
                pq.push({-ncost,next});
                dist[next]=ncost;
            }
        }
    }
    for(int i =2;i<=n;i++){
        cout<<(dist[i]==1e9?-1:dist[i])<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> v[100001];
vector<int> dijkstra(int start){
    vector<int> dist(n+1,2e9);
    priority_queue<pair<int,int>> pq;
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
    int a,b,c;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        
    }

    for(int i =1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
    }
    cin>>a>>b;
   
    vector<int> distA = dijkstra(a);
    vector<int> distB = dijkstra(b);

    cout<<distA[b]<<"\n";
    cout<<a<<" ";
    while(a!=b){
        int nxt = -1;
        for(auto[next,nc]:v[a]){
            if(distA[a]+nc + distB[next]==distA[b]){
                nxt = next;
                break;
            }
        }
        if(nxt==-1)break;
        a= nxt;
        cout<<a<<" ";
    }
}
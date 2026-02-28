#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
vector<pair<int,int>> v[100001]; 
vector<int> dijkstra(int cur){
    priority_queue<pair<int,int>> pq;
    pq.push({0,cur});
    vector<int> dist(n+1,1e9);
    dist[cur]=0;
    while(!pq.empty()){
        int cost;
        tie(cost,cur)=pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur]<cost)continue;
        for(int i =0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int ncost = v[cur][i].second+cost;
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
    int a,b,c;
    for(int i =0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<int> dist1 = dijkstra(x);
    vector<int> dist2 = dijkstra(y);
    
    int res = 1e9;

    for(int i =1;i<=n;i++){
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
    cout<<(res==1e9?-1:res)<<"\n";
}
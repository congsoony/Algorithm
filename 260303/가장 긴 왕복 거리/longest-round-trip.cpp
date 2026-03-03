#include<bits/stdc++.h> 
using namespace std;
int n,m,x;
vector<pair<int,int>> v[1001];
vector<int> dijkstra(int start){
    vector<int> dist(n+1,1e9);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dist[now]<cost) continue;
        for(int i =0;i<v[now].size();i++){
            int next = v[now][i].first;
            int nextCost = cost + v[now][i].second;
            if(nextCost<dist[next]){
                dist[next] = nextCost;
                pq.push({nextCost,next});
            }
        }
    }
    return dist;
}
int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>x;
    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    
    }
    vector<int> dist[1001];
    for(int i =1;i<=n;i++){
        dist[i] = dijkstra(i);
    }
    int res = 0;

    for(int i =1;i<=n;i++){
        res = max(res,dist[i][x] + dist[x][i]);
    }
  
    cout<<res<<"\n";
}
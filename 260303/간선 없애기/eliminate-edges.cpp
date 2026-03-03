#include<bits/stdc++.h> 
using namespace std;
int n,m;
vector<pair<int,int>> v[1001];
int arr[5001][5001];
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
            if(arr[now][next]) continue;
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
    cin>>n>>m;
    vector<pair<int,int>> iv;
    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        iv.push_back({a,b});
    }
    vector<int> dist = dijkstra(1);
    int res = 0;
    for(auto[a,b]:iv){
        arr[a][b] = arr[b][a] = 1;
        vector<int> newdist = dijkstra(1);  
        arr[a][b] = arr[b][a] = 0;
        if(newdist[n]!=dist[n]) res++;
    }
    cout<<res<<"\n";
    
}
#include<bits/stdc++.h> 
using namespace std;
int n,m;
vector<pair<int,int>> v[500];
int arr[500][500];
int parent[500];
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
            int nextCost = cost + v[now][i].second + (arr[now][next]?v[now][i].second:0);   
            if(nextCost<dist[next]){
                dist[next] = nextCost;
                pq.push({nextCost,next});
                parent[next]=now;
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
    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector<int> originaldist = dijkstra(1);
    vector<int> path;
    int cur = n;
    path.push_back(cur);
    while(cur!=1){
        for(int i =0;i<v[cur].size();i++){
            if(originaldist[cur] == originaldist[parent[cur]]+v[cur][i].second){
                cur=parent[cur];
                path.push_back(cur);
                break;
            }
        }
    }
    int res = 0;

    reverse(path.begin(),path.end());
    for(int i =1;i<path.size();i++){
        int a = path[i-1];
        int b = path[i];
        arr[a][b] = arr[b][a] = 1;
        vector<int> dist = dijkstra(1);
        arr[a][b]=arr[b][a]=0;
        res = max(res,abs(originaldist[n]-dist[n]));
    }
    cout<<res<<"\n";
}
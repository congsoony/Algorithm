#include<bits/stdc++.h>
using namespace std;
int n,m;
int person=100;
int src= 0;
int sink = 250;
vector<vector<int>> v,cost,capacity,flow;
vector<int> buy,store;

void input(){
    v= vector<vector<int>>(300);
    flow=capacity=cost = vector<vector<int>>(300,vector<int>(300));
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        v[person+i].push_back(sink);
        v[sink].push_back(person+i);
        cin>>capacity[person+i][sink];
    }
    for(int i =1;i<=m;i++){
        v[src].push_back(i);
        v[i].push_back(src);
        cin>>capacity[src][i];

    }
    for(int i =1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>capacity[i][j+person];
            if(capacity[i][j+person]){
                v[i].push_back(j+person);
                v[j+person].push_back(i);
            }
        }
    }
    for(int i =1;i<=m;i++){
        for(int j =1;j<=n;j++){
            cin>>cost[i][j+person];
            cost[j+person][i]=-cost[i][j+person];
        }
    }
}
void solve(){
    
    int res =0;
    int totalcost=0;

    while(1){
        queue<int> q;
        vector<int> inq(300),dist(300,1e9),parent(300,-1);

        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int cur =q.front();
            q.pop();
            inq[cur]=0;
            for(int next:v[cur]){
                if(dist[cur]+cost[cur][next]<dist[next]&&capacity[cur][next]-flow[cur][next]>0){
                    dist[next]=dist[cur]+cost[cur][next];
                    parent[next]=cur;
                    if(!inq[next]){
                        q.push(next);
                        inq[next]=1;
                    }
                }
            }
        }

        if(parent[sink]==-1)break;
        int amount = 1e9;
        for(int p = sink;p!=src;p=parent[p]){
            amount = min(amount,capacity[parent[p]][p]-flow[parent[p]][p]);
        }
        for(int p = sink;p!=src;p=parent[p]){
            totalcost+=amount*cost[parent[p]][p];
            flow[parent[p]][p]+=amount;
            flow[p][parent[p]]-=amount;
        }
        res+=amount;
    }
    cout<<res<<"\n";
    cout<<totalcost<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    
}
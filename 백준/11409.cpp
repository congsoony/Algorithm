#include <bits/stdc++.h>
using namespace std;
/*
#define MAX_V 1000
const int inf = 1e9;
int V;
int capacity[MAX_V][MAX_V] , flow[MAX_V][MAX_V];
int networkFlow(int source, int sink){
    memset(flow,0,sizeof(flow));
    int totalFlow = 0;
    while(true){
        vector<int> parent(MAX_V,-1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int next=0;next<V;next++){
                if(capacity[cur][next]-flow[cur][next]>0 &&parent[next]==-1){
                    q.push(next);
                    parent[next]=cur;
                }
            }
        }

        if(parent[sink]==-1)break;

        int amount = inf;
        for(int p=sink;p!=source;p=parent[p])
            amount = min(amount,capacity[parent[p]][p]-flow[parent[p]][p]);
        for(int p=sink;p!=source;p=parent[p]){
            flow[parent[p]][p]+=amount;
            flow[p][parent[p]]-=amount;
        }
        totalFlow+=amount;
    }


    return totalFlow;
}
*/

int n,m;
int source = 900,sink=901;
vector<int> v[1000];
int flow[1000][1000], c[1000][1000],cost[1000][1000];
int work = 400;
void input(){
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        v[i].push_back(source);
        v[source].push_back(i);
        c[source][i]=1;
    }
    for(int i =1;i<=m;i++){
        v[i+work].push_back(sink);
        v[sink].push_back(i+work);
        c[i+work][sink]=1;
    }
    for(int i =1;i<=n;i++){
        int w;
        cin>>w;
        int num,pay;
        for(int j=0;j<w;j++){
            cin>>num>>pay;
            v[i].push_back(num+work);
            v[num+work].push_back(i);
            
            c[i][num+work]=1;
            cost[i][num+work]=-pay;
            cost[num+work][i]=+pay;
        }
    }
}
void solve(){
    int totalflow=0;
    vector<int> inq(1000);
    int res = 0;
    int cnt =0;
    while(true){
        vector<int>parent(1000,-1),dist(1000,1e9);
        queue<int> q;
        q.push(source);
        inq[source]=0;
        dist[source]=0;
        parent[source]=source;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            inq[cur]=0;
            for(int next:v[cur]){
                if(c[cur][next]-flow[cur][next]>0 &&dist[next]>dist[cur]+cost[cur][next]){
                    dist[next]=dist[cur]+cost[cur][next];
                    parent[next]=cur;
                    if(inq[next]==false){
                        q.push(next);
                        inq[next]=true;
                    }
                }
            }
        }

        if(parent[sink]==-1)break;
        int amt =1e9;
        for(int p=sink;p!=source;p=parent[p])
            amt=min(amt,c[parent[p]][p]-flow[parent[p]][p]);
        for(int p =sink;p!=source;p=parent[p]){
            flow[parent[p]][p]+=amt;
            flow[p][parent[p]]-=amt;
            res+=amt*cost[parent[p]][p];
        }
        cnt++;
    }
    cout<<cnt<<"\n";
    cout<<-res<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();

}
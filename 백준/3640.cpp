#include<bits/stdc++.h>
using namespace std;
int MAX_V=2005;
int half= 1000;
int n ,m;
vector<vector<int>> v,cap,flow,cost;
int sum=0;
int src,sink;
void add(int a,int b,int val,int f=1){
    v[a].push_back(b);
    v[b].push_back(a);
    cap[a][b]=f;
    cost[a][b]=val;
    cost[b][a]=-val;
}
void input(){
    v = vector<vector<int>>(MAX_V);
    cost=cap = flow = vector<vector<int>>(MAX_V,vector<int>(MAX_V));
    int a,b,c;
    src = MAX_V-2;
    sink = MAX_V-1;
    add(src,1,0,2);
    add(1,1+half,0,2);
    add(n,n+half,0,2);
    add(n+half,sink,0,2);
    for(int i =2;i<n;i++)
        add(i,i+half,0);
    for(int i =0;i<m;i++){
        cin>>a>>b>>c;
        add(a+half,b,c);
    }
    src = 1;
    sink = n;
}

void solve(){
    vector<int> inq(MAX_V);
    int total = 0;
    while(1){
        vector<int> parent(MAX_V,-1),dist(MAX_V,1e9);
        dist[src]=0;
        parent[src]=src;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int cur =q.front();
            q.pop();
            inq[cur]=0;
            for(int next:v[cur]){
                if(dist[next]>dist[cur]+cost[cur][next] && cap[cur][next]-flow[cur][next]>0){
                    dist[next]=dist[cur]+cost[cur][next];
                    parent[next]=cur;
                    if(inq[next]==0){
                        inq[next]=1;
                        q.push(next);
                    }
                }
            }
        }

        if(parent[sink]==-1)break;
        int amt = 1e9;
        for(int p=sink;p!=src;p=parent[p]){
            amt = min(amt,cap[parent[p]][p]-flow[parent[p]][p]);
        }
        for(int p=sink;p!=src;p=parent[p]){
            flow[parent[p]][p]+=amt;
            flow[p][parent[p]]-=amt;
            total+=cost[parent[p]][p]*amt;
        }
    }
    cout<<total<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    while(cin>>n>>m){
        input();
        solve();
    }
}
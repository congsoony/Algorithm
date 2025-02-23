#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> v,capacity,flow;
void input(){
    cin>>n>>m;
    v = vector<vector<int>>(n+1);
    capacity = flow = vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        capacity[a][b]=1;
    }
}
int fordfulkerson(){
    int src = 1;
    int sink = 2;
    int res =  0;
    vector<int> check(n+1,1);
    while(1){
        queue<int> q;
        vector<int> parent(n+1,-1);
        q.push(src);
        parent[src]=src;
        while(!q.empty()){
            int cur =q.front();
            q.pop();
            for(int next:v[cur]){
                if(parent[next]==-1&&capacity[cur][next]-flow[cur][next]>0){
                    parent[next]=cur;
                    q.push(next);
                }
            }
        }
        if(parent[sink]==-1)break;
        int minflow = 1e9;
        for(int p=sink;p!=src;p=parent[p]){
            minflow=min(minflow,capacity[parent[p]][p]-flow[parent[p]][p]);
        }
        for(int p=sink;p!=src;p=parent[p]){
            flow[parent[p]][p]+=minflow;
            flow[p][parent[p]]-=minflow;
        }
        res++;
    }
    return res; 
}
void solve(){
    cout<<fordfulkerson()<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve();
    
}
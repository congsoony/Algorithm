#include<bits/stdc++.h>
using namespace std;
#define MAX 900
int n,m;
vector<vector<int>> v,capacity,flow;
int out=400;

void input(){
    cin>>n>>m;
    v = vector<vector<int>>(MAX);
    capacity = flow = vector<vector<int>>(MAX,vector<int>(MAX));

    for(int i=1;i<=n;i++){
        v[i].push_back(i+out);
        v[out+i].push_back(i);
        capacity[i][i+out]=1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a+out].push_back(b);
        v[b].push_back(a+out);

        v[b+out].push_back(a);
        v[a].push_back(b+out);


        capacity[a+out][b]=1;
        capacity[b+out][a]=1;
    }
}
int fordfulkerson(){
    int src = 401;
    int sink = 2;
    int res =  0;
    while(1){
        queue<int> q;
        vector<int> parent(MAX+1,-1);
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
            cout<<parent[p]<<" "<<p<<endl;
            flow[parent[p]][p]+=minflow;
            flow[p][parent[p]]-=minflow;
        }
        res+=minflow;
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
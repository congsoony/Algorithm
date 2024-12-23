#include <bits/stdc++.h>
using namespace std;

vector<int>v,indegree;
vector<vector<int>>adj;
int n,m;
void input(){
    cin>>n;
    v= vector<int>(n);
    for(int i=0;i<n;i++)cin>>v[i];
    adj = vector<vector<int>>(n+1,vector<int>(n+1));
    indegree= vector<int>(n+1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            adj[v[j]][v[i]]=1;
            indegree[v[i]]++;
        }
    }
    cin>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(adj[a][b]){
            adj[a][b]=0;
            indegree[b]--;
            adj[b][a]=1;
            indegree[a]++;
        }
        else{
            indegree[a]--;
            adj[b][a]=0;
            adj[a][b]=1;
            indegree[b]++;
        }
    }

}

void solve(){

    
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>res;
    while(!q.empty()){
        if(q.size()>=2){
            cout<<"?\n";
            return;
        }
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for(int i=1;i<=n;i++){
            if(adj[cur][i]){
                if(--indegree[i]==0){
                    q.push(i);
                }
            }
        }
    }
    if(res.size()!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(int i:res)cout<<i<<" ";
    cout<<"\n";
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    int test;
    cin>>test;
    while(test--){
        input();
        solve();
    }
    
}

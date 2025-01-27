#include <bits/stdc++.h>
using namespace std;
int n,k,d;
int MAXV= 500;
int food =300;
int src=401,sink=402;
vector<vector<int>> v,capacity,flow;
void input(){
   cin>>n>>k>>d;
   v = vector<vector<int>>(MAXV);
   flow=capacity = vector<vector<int>>(MAXV,vector<int>(MAXV));
   for(int i =1;i<=d;i++){
      int t;
      cin>>t;
      v[i+food].push_back(sink);
      v[sink].push_back(i+food);
      capacity[i+food][sink]=t;     
   }
   for(int i =1;i<=n;i++){
      int t,c; 
      cin>>t;
      for(int j=0;j<t;j++){
         cin>>c;
         v[i].push_back(c+food);
         v[c+food].push_back(i);
         capacity[i][c+food]=1;
      }
      v[src].push_back(i);
      v[i].push_back(src);
      capacity[src][i]=k;
   }
}

void solve(){
   int res = 0;
   while(true){
      vector<int> parent(MAXV,-1);
      queue<int> q;
      int amt=1e9;
      q.push(src);
      while(!q.empty()){
         int cur =q.front();
         q.pop();
         for(int next:v[cur]){
            if(parent[next]==-1 && capacity[cur][next]-flow[cur][next]>0){
               parent[next]=cur;
               q.push(next);
            }
         }
      }
      if(parent[sink]==-1)break;
      for(int p =sink;p!=src;p=parent[p]){
         amt = min(amt,capacity[parent[p]][p]-flow[parent[p]][p]);
      }
      for(int p =sink;p!=src;p=parent[p]){
         flow[parent[p]][p]+=amt;
         flow[p][parent[p]]-=amt;
      }
      res+=amt;
   }
   cout<<res<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve();

}
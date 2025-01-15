#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> v,scc_v;
vector<int> check,st,finished,atm,restaurant,scc_atm,dp;
vector<int> scc_restaurant,scc_indegree;
int n,m;
int s,p;
int cnt,scc;
void input(){
    cin>>n>>m;
    v= vector<vector<int>>(n+1);
    scc_restaurant=scc_indegree=dp = scc_atm=restaurant=atm = check = finished = vector<int>(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);

    }
    for(int i =1;i<=n;i++){
        cin>>a;
        atm[i]=a;
    }
    cin>>s>>p;
    for(int i=0;i<p;i++){
        cin>>a;
        restaurant[a]=1;
    }

}

int dfs(int cur){
    check[cur]=++cnt;
    st.push_back(cur);
    int result = check[cur];
    for(int next:v[cur]){
        if(!check[next])result = min(result,dfs(next));
        else if(!finished[next])result = min(result,check[next]);
    }
    if(result==check[cur]){
        scc++;
        while(1){
            int t = st.back();
            st.pop_back();
            finished[t]=scc;
            if(t==cur)break;
        }
    }
    return result;
}
int topology(){
    int res = 0;
    bool is_start=false;
    queue<int> q;
    //단순히 q.push(finished[s]) 이것만으로 불가능
    for(int i=1;i<=scc;i++){
        if(scc_indegree[i]==0){
            q.push(i);
            //dp[i]=scc_atm[i]; 이표현 불가능 거처가는 레스토랑이 아닐수도있기때문에
        }
    }
    dp[finished[s]]=scc_atm[finished[s]];
    while(!q.empty()){
        int cur =q.front();
        q.pop();
        if(cur==finished[s])is_start=1;
        for(int next:scc_v[cur]){
            if(is_start)dp[next]=max(dp[next],dp[cur]+scc_atm[next]);
            scc_indegree[next]--;
            if(scc_indegree[next]==0)
                q.push(next);
        }
    }
    for(int i=1;i<=scc;i++){
        if(scc_restaurant[i])
            res =max(res,dp[i]);
    }
    return res;
}
int bfs(){
    int res = 0;
    queue<int> q;
    q.push(finished[s]);
    dp[finished[s]]=scc_atm[finished[s]];
    while(!q.empty()){
        int cur =q.front();
        q.pop();
        for(int next:scc_v[cur]){
            if(dp[next]<dp[cur]+scc_atm[next]){
                q.push(next);
                dp[next]=dp[cur]+scc_atm[next];
            }
        }
    }
    for(int i=1;i<=scc;i++){
        if(scc_restaurant[i]){
            res = max(res,dp[i]);
        }
    }
    return res;
}
void solve(){ 
    //scc 구성
    for(int i=1;i<=n;i++){
        if(check[i]==0)
            dfs(i);
    }
    scc_v = vector<vector<int>>(scc+1);
    //scc의atm과 레스토랑 재구성
    for(int i=1;i<=n;i++){
        scc_atm[finished[i]]+=atm[i];
        if(restaurant[i])scc_restaurant[finished[i]]=1;
    }
    //scc 의 그래프 재구성
    for(int i=1;i<=n;i++){
        for(int next:v[i]){
            if(finished[i]==finished[next])continue;
            scc_v[finished[i]].push_back(finished[next]);
            scc_indegree[finished[next]]++;
        }
    }

    //둘중 아무거나 사용가능
    cout<<topology()<<"\n"; 
    //cout<<bfs()<<"\n";
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}

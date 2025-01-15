//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,s,t;
vector<vector<int>> v,sccv;
int cnt,scc;
vector<int> sccid,check,st,sccnum,scc_indegree;
void input(){
    cin>>n>>m>>s>>t;
    v =vector<vector<int>>(n+1);
    sccnum= check = sccid = vector<int>(n+1);
    int a,b;
    for(int i =0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
    }
}

int dfs(int cur){
    st.push_back(cur);
    int result = check[cur]= ++cnt;
    for(int next:v[cur]){
        if(check[next]==0){
            result = min(result,dfs(next));
        }
        else if(sccid[next]==0){
            result = min(result,check[next]);
        }
    }
    if(result ==check[cur]){
        scc++;
        int cnt2 = 0;
        while(1){
            int t = st.back();
            st.pop_back();
            sccid[t]=scc;
            cnt2++;
            if(t==cur)break;
        }
        sccnum[scc]=cnt2;
    }
    return result;
}
int bfs(){
    queue<int> q;
    q.push(sccid[s]);
    vector<int> dp(scc+1);
    dp[sccid[s]]=sccnum[sccid[s]];
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int next:sccv[cur]){
            if(dp[next]<dp[cur]+sccnum[next]){
                q.push(next);
                dp[next]=dp[cur]+sccnum[next];
            }
        }
    }
    return dp[sccid[t]];

}
void solve(){
    for(int i=1;i<=n;i++){
        if(check[i]==0)
            dfs(i);
    }
    sccv = vector<vector<int>>(scc+1);
    //scc_indegree = vector<int>(scc+1);
    for(int i=1;i<=n;i++){
        for(int next:v[i]){
            if(sccid[i]==sccid[next])continue;
            sccv[sccid[i]].push_back(sccid[next]);
            //scc_indegree[sccid[next]]++;
        }
    }
    cout<<bfs()<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
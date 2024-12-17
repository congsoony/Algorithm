//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<pair<ll,ll>> v[100000];
vector<ll>res;
ll _max = -1;
int start= -1;
void input(){
    cin>>n;
    ll a,b,c;
    for(int i =0;i<n-1;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
}
void dfs(int cur,int parent=-1,ll sum=0){
    res[cur]=max(res[cur],sum);
    if(sum>_max){
        start=cur;
        _max=sum;
    }
    for(auto [next,cost] : v[cur]){
        if(next==parent)continue;
        dfs(next,cur,sum+cost);
    }
}
void solve(){
    res = vector<ll>(n+1);
    start=1;
    for(int i=0;i<3;i++){
       _max = -1;
       dfs(start);
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
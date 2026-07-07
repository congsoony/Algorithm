#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

ll dp[100005][2][2][3];
string n;

void input(){
    cin>>n;
}

ll dfs(ll idx,ll is_less ,ll has_369,ll mod3){
    if(idx>=n.size()){
        return has_369 || mod3==0;
    }
    ll &cache = dp[idx][is_less][has_369][mod3];
    if(cache!=-1)return cache;

    ll limit = is_less ? 9:n[idx]-'0';
    ll ret = 0;
    for(ll i= 0;i<=limit;i++){
        ll next_is_less = is_less || (i<(n[idx]-'0'));
        ll next_has_369 = has_369 || (i==3||i==6||i==9);
        ll next_mod3 = (mod3*10 + i)%3;

        ret = (ret + dfs(idx+1,next_is_less, next_has_369,next_mod3))%mod;
    }
    return cache = ret;

}
void solve(){
    memset(dp,-1,sizeof(dp));
    ll ret = dfs(0,0,0,0);
    
    cout<<(ret-1)%mod<<endl;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();

}
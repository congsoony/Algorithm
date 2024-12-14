#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
vector<ll>v;
void input(){
    cin>>n>>k;
    v = vector<ll>(n);
    for(int i=0;i<n;i++)cin>>v[i];
}

void solve(){
    vector<ll>num(100001);

    ll res = 0;
    ll l=0;
    ll one=0;
    for(int i=0;i<n;i++){
        one+=v[i]%2;
        while(one>k){
            one-=v[l++]%2;
        }
        res = max(res,i-l-one+1);
    }
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve();
    
}

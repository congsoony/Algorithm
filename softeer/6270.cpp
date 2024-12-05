#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v1,v2;
ll n,m;
void input(){
    cin>>n>>m;
    v1=v2=vector<ll>(1001);

    ll sum = 0;
    for(int i =0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        for(int j =0;j<a;j++){
            v1[++sum]=b;
        }
    }
    sum = 0;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        for(int j =0;j<a;j++){
            v2[++sum]=b;
        }
    }
    
}
void solve(){
    ll res = 0;
    for(int i=1;i<=100;i++)res = max(res,v2[i]-v1[i]);
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}

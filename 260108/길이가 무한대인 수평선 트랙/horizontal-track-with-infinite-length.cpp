#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    cin>>n>>t;
    ll a,b;
    vector<ll> v(n);
    for(int i =0;i<n;i++){
        cin>>a>>b;
        v[i]=a + b*t;
    }
    ll cur = 2e18;
    int res = 0;
    for(int i =n-1;i>=0;i--){
        if(v[i]<cur){
            res++;
            cur= v[i];
        }
    }
    cout<<res<<"\n";
}
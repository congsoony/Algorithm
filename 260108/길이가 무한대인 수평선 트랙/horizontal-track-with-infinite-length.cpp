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
    set<ll> s;
    for(int i =0;i<n;i++){
        cin>>a>>b;
        ll c = a+b*t;
        auto it = s.lower_bound(c);
        if(it!=s.end())
            s.erase(it);
        s.insert(c);
    }
    cout<<s.size()<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    freopen("input.txt","r",stdin);
    ll n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> v;
    for(int i =0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int l = 0;
    ll res = v[0].second;
    ll sum=res;
    for(int i =1;i<n;i++){
        while(v[i].first-v[l].first>2*k&&l<=i){
            sum-=v[l++].second;
        }
        sum+=v[i].second;
        res = max(res,sum);
    }
    cout<<res<<"\n";
}
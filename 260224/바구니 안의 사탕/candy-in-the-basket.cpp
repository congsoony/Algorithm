#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,k;
    cin>>n>>k;
    ll offset = 2e6;
    vector<ll>sum(5e6+1);
    for(int i =0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sum[b+offset]=a;
    }

    for(int i =offset;i<offset+1e6;i++){
        sum[i] +=sum[i-1];
    }
    ll res = 0;
    for(int i =offset+1;i<=offset+2e6;i++){
        res = max(res,sum[i]-sum[i-2*k-1]);
    }
    cout<<res<<"\n";
}
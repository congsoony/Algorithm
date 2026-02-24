#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    freopen("input.txt","r",stdin);
    ll n,k;
    cin>>n>>k;
    ll offset = 4e6;
    vector<ll>sum(9e6);
    for(int i =0;i<n;i++){
        int a,b;
        cin>>a>>b;
        sum[b+offset]=a;
    }

    for(int i =offset+1;i<offset+2e6;i++){
        sum[i] +=sum[i-1];
    }
    ll res = 0;
    for(int i =offset+1;i<=offset+2e6;i++){
        res = max(res,sum[i]-sum[i-2*k-1]);
    }
    cout<<res<<"\n";
}
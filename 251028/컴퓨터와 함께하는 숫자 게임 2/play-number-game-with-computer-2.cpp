#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    freopen("input.txt","r",stdin);
    ll m,a,b;
    cin>>m;
    cin>>a>>b;
    ll l=1,r=m;
    int cnt = 0;
    int res = 1e9;
    while(l<=r){
        ll mid = (l+r)/2;
        cnt++;
        if(a<=mid && mid<=b)
            res = min(res,cnt);
        if(b<mid){
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<" " <<ceil(log2(m))<<"\n";
}
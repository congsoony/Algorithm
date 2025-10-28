#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    freopen("input.txt","r",stdin);
    ll m,a,b;
    cin>>m;
    cin>>a>>b;
    int res = 1e9;
    int res2=0;
    for(ll i=a;i<=b;i++){
        ll l=1,r=m;
        int cnt = 0;
        
        while(l<=r){
            ll mid = (l+r)/2;
            cnt++;
            if(a<=mid && mid<=b)
                res = min(res,cnt);
            if(i<mid){
                r = mid-1;
            }
            else if(i==mid)
                break;
            else{
                l= mid+1;
            }

        }
        res2= max(res2,cnt);
    }
    cout<<res<<" " <<res2<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin>>n;
    ll l=1,r = n*n;
    ll res = n*n;
    while(l<=r){
        ll mid = (l+r)/2;
        ll cnt = mid -  (mid/3 + mid/5 - mid/15);

        if(cnt >=n){
            r = mid-1;
            res = min(res,mid);
        }
        else{
            l=mid+1;
            
        }
    }
    cout<<res<<"\n";
}
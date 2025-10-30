#include<bits/stdc++.h>

using namespace std;
#define ll long long
int n, m;
int arr[100000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    ll l = 1,r=1e15;
    ll res = 1e15;
    while(l<=r){
        ll mid = (l+r)/2;
        ll cnt = 0;
        for(int i =0;i<m;i++){
            cnt+=mid/arr[i];
        }
        if(cnt>=n){
            r = mid-1;
            res = min(res,mid);
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<"\n";
    return 0;
}

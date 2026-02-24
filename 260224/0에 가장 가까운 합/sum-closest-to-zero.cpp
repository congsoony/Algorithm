#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    freopen("input.txt","r",stdin);
    cin>>n;
    vector<int>v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int res = 2e9;
    for(int i =0;i<n;i++){
        int idx = lower_bound(v.begin(),v.begin()+i,-v[i])-v.begin();
        if(idx!=i && idx !=n){
            res = min(res,abs(v[i]+v[idx]));
        }
        idx = lower_bound(v.begin()+i+1,v.end(),-v[i])-v.begin();
        if(idx!=i&&idx!=n){
            res = min(res,abs(v[i]+v[idx]));
        }
    }
    cout<<res<<"\n";
}
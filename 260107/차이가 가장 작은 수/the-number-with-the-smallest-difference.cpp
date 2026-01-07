#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int res = 2e9;
    for(int i =0;i<n;i++){
        int c = lower_bound(v.begin()+i+1,v.end(),m+v[i])-v.begin();
        if(c == v.size())continue;
        res = min(res,abs(v[c]-v[i]));
    }
    cout<<(res==2e9?-1:res)<<"\n";
}
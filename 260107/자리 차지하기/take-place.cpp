#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    set<int,greater<int>> s;
    for(int i =1;i<=k;i++)s.insert(i);
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end(),greater<int>());
    int res = 0;
    for(int i =0;i<n;i++){
        auto it =s.lower_bound(v[i]);
        if(it==s.end())break;
        s.erase(it);
        res++;
    }
    cout<<res<<"\n";
}
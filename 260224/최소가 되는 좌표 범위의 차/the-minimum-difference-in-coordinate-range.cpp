#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> v;
    for(int i =0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int res = 1e9;
    int l =0;
    for(int i =1;i<n;i++){
        while(l<i &&abs(v[l].second - v[i].second)<d){
            l++;
        }
        if(abs(v[l].second-v[i].second)>=d)
            res = min(res,v[i].first-v[l].first);
    }
    cout<<res<<"\n";
}
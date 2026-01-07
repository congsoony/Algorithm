#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    set<pair<int,int>> s;
    int x,y;
    for(int i =0;i<n;i++){
        cin>>x>>y;
        s.insert({x,y});
    }
    for(int i =0;i<m;i++){
        cin>>x;
        auto it = s.lower_bound({x,0});
        if(it==s.end()){
            cout<<"-1 -1"<<"\n";
        }
        else{
            cout<<it->first<<" "<<it->second<<"\n";
            s.erase(it);
        }
    }

}
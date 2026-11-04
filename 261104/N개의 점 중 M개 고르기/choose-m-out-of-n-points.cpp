#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<int> p;
int n,m;
int dfs(int h=0,int idx=0){
    if(h>=m){
        int s= 0;
        for(int i =0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                int x = v[p[i]].first - v[p[j]].first;
                int y = v[p[i]].second - v[p[j]].second;
                s = max(s,x*x + y*y);
            }
        }
        return s;
    }
    int res = 1e9;
    for(int i =idx;i<n;i++){
        p[h]=i;
        res = min(res,dfs(h+1,i+1));
    }
    return res;
}
int main() {
    cin>>n>>m;
    p.resize(m);
    v.resize(n);
    for(int i =0;i<n;i++)cin>>v[i].first>>v[i].second;
    cout<<dfs()<<"\n";
}
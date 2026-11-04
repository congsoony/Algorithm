#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v,v2;
int dfs(int h=0,int idx=0){
    if(h>=m){
        int t = 0;
        for(int i=0;i<m;i++)t^=v2[i];
        return t;
    }
    int res = 0;
    for(int i=idx;i<n;i++){
        v2[h]=v[i];
        res = max(res,dfs(h+1,i+1));
    }
    return res;
}
int main() {
    cin>>n>>m;
    v =vector<int>(n);
    v2 = vector<int>(m);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    cout<<dfs();
}
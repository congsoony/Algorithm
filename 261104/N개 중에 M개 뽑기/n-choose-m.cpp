#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
void dfs(int h=0,int idx=0){
    if(h>=m){
        for(int i=0;i<m;i++){
            cout<<v[i]+1<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=idx;i<n;i++){
        v[h]=i;
        dfs(h+1,i+1);
    }
}
int main() {
    cin>>n>>m;
    v=vector<int>(m);
    dfs();
}
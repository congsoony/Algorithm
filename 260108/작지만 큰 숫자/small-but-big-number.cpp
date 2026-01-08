#include <bits/stdc++.h>
using namespace std;

int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    int n,m;
    set<int,greater<int>> s;
    cin>>n>>m;
    int a;
    for(int i =0;i<n;i++){
        cin>>a;
        s.insert(a);
    }
    for(int i =0;i<m;i++){
        cin>>a;
        auto it = s.lower_bound(a);
        if(it!=s.end()){
            cout<<*it<<"\n";
            s.erase(it);
        }
        else{
            cout<<-1<<"\n";
        }
    }
}
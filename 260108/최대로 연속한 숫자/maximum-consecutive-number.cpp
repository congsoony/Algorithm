#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n,m;
int longest(){
    int l = -1;
    int res = 0;
    for(int i:s){
        res = max(res,i-l-1);
        l = i;
    }
    res = max(res,n-l);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    
    cin>>n>>m;
    int a;

    for(int i=0;i<m;i++){
        cin>>a;
        s.insert(a);
        cout<<longest()<<"\n";
    }
}
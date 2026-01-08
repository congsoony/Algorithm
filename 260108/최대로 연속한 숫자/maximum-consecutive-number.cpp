#include <bits/stdc++.h>
using namespace std;
set<int> s;
multiset<int> leng;
int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    
    cin>>n>>m;
    int a;
    s.insert(-1);
    s.insert(n+1);
    leng.insert(n+1);


    for(int i=0;i<m;i++){
        cin>>a;
        auto it = s.lower_bound(a);
        int r = *it;
        int l = *prev(it);
        int blen = r-l-1;
        leng.erase(blen);
        int leftlen = a-l-1;
        int rightlen = r-a-1;
        leng.insert(leftlen);
        leng.insert(rightlen);
        s.insert(a);
        cout<<*leng.rbegin()<<"\n";
    }
}
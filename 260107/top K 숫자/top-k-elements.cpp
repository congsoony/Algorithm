#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    set<int,greater<int>> s;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        s.insert(a);
    }

    for(int i=0;i<k;i++){
        cout<<*s.begin()<<" ";
        s.erase(s.begin());
    }
}
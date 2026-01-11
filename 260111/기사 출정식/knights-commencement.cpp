#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
unordered_map<int,list<int>::iterator> pos;
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    int t;
    list<int> l;
    for(int i =0;i<n;i++){
        cin>>t;
        l.push_back(t);
        pos[t]=prev(l.end());
    }
    for(int i =0;i<m;i++){
        cin>>t;
        auto left = next(pos[t]);
        auto right = prev(pos[t]);
        if(left==l.end())
            left++;
        if(right==l.end())
            right--;
        l.erase(pos[t]);
        cout<<*left<<" "<<*right<<"\n";
    }
}
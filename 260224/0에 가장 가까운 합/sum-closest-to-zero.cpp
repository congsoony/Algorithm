#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin>>n;
    vector<int>v(n);
    for(int &a:v)cin>>a;
    sort(v.begin(),v.end());
    int l =0,r=n-1;

    int res =2e9;
    while(l<r){
        if(r+l>0){
            res = min(res,abs(v[r--]+v[l]));
        }
        else{
            res = min(res,abs(v[r]+v[l--]));
        }
    }
    cout<<res<<"\n";
}
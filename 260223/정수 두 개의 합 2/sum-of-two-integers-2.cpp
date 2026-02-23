#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &a:v)cin>>a;
    sort(v.begin(),v.end());
    long long res = 0;
    for(int i =0;i<n;i++){
        res+=upper_bound(v.begin()+i,v.end(),k-v[i])-lower_bound(v.begin()+i,v.end(),k-v[i]);
    }
    cout<<res<<"\n";
}
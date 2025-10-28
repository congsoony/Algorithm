#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    for(int i =0;i<m;i++){
        int t;
        cin>>t;
        cout<<upper_bound(v.begin(),v.end(),t)-lower_bound(v.begin(),v.end(),t)<<"\n";      
    }
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    for(int i =0;i<m;i++){
        int x,y;
        cin>>x>>y;
        cout<<upper_bound(v.begin(),v.end(),y)-lower_bound(v.begin(),v.end(),x)<<"\n";
    }
}
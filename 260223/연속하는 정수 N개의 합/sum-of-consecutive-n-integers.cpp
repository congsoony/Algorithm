#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    long long sum=0;
    int res = 0;
    int l=0,r=0;
    while(l<=r &&r<n){
        if(sum<m){
            sum+=v[r++];
        }
        else{
            sum-=v[l++];
        }
        res+=sum==m;
    }
    cout<<res<<"\n";
}
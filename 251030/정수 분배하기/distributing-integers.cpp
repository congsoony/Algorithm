#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    int l=1,r = 1e9;
    int res = 0 ;
    while(l<=r){
        int mid = (l+r)/2;
        int cnt = 0;
        for(int val : v){
            cnt+=val/mid;
        }
        if(cnt>=m){
            l=mid+1;
            res = max(res,mid);
        }
        else{
            r = mid-1;
        }
    } 
    cout<<res<<"\n";
}
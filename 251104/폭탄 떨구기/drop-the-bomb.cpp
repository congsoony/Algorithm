#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>k;
    v.resize(n);
    for(int i =0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());

    int l=1,r = 1e9;
    int res = 1e9;

    while(l<=r){
        int mid = (l+r)/2;
        int f = v[0]+mid*2;
        int cnt =1;
        for(int i =1;i<n;i++){
            if(f<v[i]){
                cnt++;
                f=v[i]+mid*2;
            }
        }
        if(cnt<=k){
            res = min(res,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
int n,m,c;
vector<int>v;
int main() {
    freopen("input.txt","r",stdin);
    cin>>n>>m>>c;
    v.resize(n);
    for(int i =0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());

    int l=1,r = 1e9;
    int res = 1e9;
    while(l<=r){
        int mid = (l+r)/2;
        int cnt = 1;
        int bus =1;
        int f=v[0];
        for(int i=1;i<n;i++){
            if(cnt==c){
                f=v[i];
                cnt=1;
                bus++;
                continue;
            }
            if(v[i]-f>mid){
                cnt=0;
                bus++;
                f=v[i];
            }
            cnt++;
        }
        if(bus<=m){
            res = min(res,mid);
            r = mid-1;
        }
        else{
            l=mid+1;
        }

    }
    cout<<res<<"\n";
}
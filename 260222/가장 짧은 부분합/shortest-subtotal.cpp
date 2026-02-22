#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,s;
    cin>>n>>s;
    vector<ll> v(n+1),sum(n+1);
    for(int i =1;i<=n;i++){
        cin>>v[i];
        sum[i]= sum[i-1]+v[i];
    }
    int j=1;
    int res = 1e9;
    for(int i =0;i<n;i++){
        while(j<=n&&sum[j]-sum[i]<s){
            j++;
        }
        if(sum[j]-sum[i]>=s){
            res = min(res,j-i);
        }
    }
    cout<<(res==1e9?-1:res)<<"\n";

}
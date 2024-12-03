#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t;
vector<ll> v1[100000],v2[100000];
void input(){
    cin>>n>>t;
    for(int i =0;i<t;i++){
        v1[i].resize(n+1);
        v2[i].resize(n+1);
        for(int j =0;j<n-1;j++){
            cin>>v1[i][j]>>v2[i][j];
        }
        cin>>v1[i][n-1];
    }
}

void solve(){
    for(int i =0;i<t;i++){
        ll l =1;
        ll r =1e18;
        ll res = 0;
        while(l<=r){
            ll mid = (l+r)/2;
            vector<ll>temp = v1[i];
            bool flag=true;
            for(int j =0;j<n;j++){
                if(temp[j]>=mid){
                    temp[j+1]+=v2[i][j];
                }
                else if(temp[j]+v2[i][j]>=mid){
                    temp[j+1] +=temp[j]+v2[i][j]-mid;
                }
                else{
                    flag=false;
                    break;
                }
            }

            if(flag){
                l =mid+1;
                res = max(res,mid);
            }
            else{
                r=mid-1;
            }
        }
        cout<<res<<"\n";
    }
    
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();
    
}
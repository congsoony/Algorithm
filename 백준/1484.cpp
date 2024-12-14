#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll g;
void input(){
    cin>>g;
}

void solve(){
    vector<ll> res;
    for(ll i=1;i<=g;i++){
        ll l= 1,r = i;
        while(l<=r){
            ll mid = (l+r)/2;
            if(i*i - mid*mid ==g){
                res.push_back(i);
                break;
            }
            else if(i*i - mid*mid >g){
                l=mid+1;
            }
            else{
                r= mid-1;
            }
        }
    }
    sort(res.begin(),res.end());
    if(res.size()==0){
        cout<<-1<<"\n";
        return;
    }
    for(ll val:res){
        cout<<val<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    input();
    solve();
    
}

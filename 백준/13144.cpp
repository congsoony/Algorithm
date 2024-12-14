#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<ll>v;
void input(){
    cin>>n;
    v = vector<ll>(n);
    for(int i=0;i<n;i++)cin>>v[i];
}

void solve(){
    vector<ll>num(100001);

    ll res = 0;
    int l=0;
    for(int i=0;i<n;i++){
        num[v[i]]++;
        while(num[v[i]]>1){
            num[v[l++]]--;
        }
        res+=i-l+1;
    }
    cout<<res<<"\n";

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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll h,k,r;
queue<ll>q[1<<13];
vector<ll> v[1<<13];
void input(){
    cin>>h>>k>>r;
    ll a;
    for(int i =1<<h;i<(1<<(h+1));i++){
        for(int j=0;j<k;j++){
            cin>>a;
            v[i].push_back(a);
        }
    }
}
void solve(){
    ll res = 0;
    ll day=0;
    while(day<r){
        for(int i=1;i<(1<<h);i++){
            if(!q[i*2+day%2].empty()){
                ll val = q[i*2+day%2].front();
                q[i*2+day%2].pop();
                q[i].push(val);
            }
        }
        for(int i =1<<h;i<(1<<(h+1));i++){
            if(day<v[i].size()){
                q[i].push(v[i][day]);
            }
        }
        day++;
    }
    while(!q[1].empty()){
        res +=q[1].front();
        q[1].pop();
    }
    cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}

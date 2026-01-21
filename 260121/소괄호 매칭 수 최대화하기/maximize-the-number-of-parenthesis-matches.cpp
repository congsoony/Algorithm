#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    // 입출력 속도 향상
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<tuple<ll,ll,string>> v;
    cin>>n;
    for(int i =0;i<n;i++){
        string s;
        cin>>s;
        int cnt[2]={0};
        for(char c:s)cnt[c==')']++;
        v.push_back({cnt[0],cnt[1],s});
    }
    sort(v.begin(),v.end(),[&](tuple<ll,ll,string> &a,tuple<ll,ll,string> &b)->int{
        return get<0>(a)*get<1>(b)> get<0>(b)*get<1>(a);
    });
    ll res = 0;
    ll cnt =0;
    for(auto i :v){
        for(char c:get<2>(i)){
            if(c=='(')cnt++;
            else res+=cnt;
        }
    }
    cout<<res<<"\n";
}
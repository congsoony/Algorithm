#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;

int main() {
    freopen("input.txt","r",stdin);
    cin>>n;
    priority_queue<tuple<ll,ll,ll>> pq,park;
    ll a,t,idx;
    for(int i =0;i<n;i++){
        cin>>a>>t;
        pq.push({-a,t,i});
    }
    ll res = 0;
    tie(a,t,idx)= pq.top();
    a = -a;
    ll cur = a;
    while(!pq.empty() || !park.empty()){
        while(!pq.empty()&& cur>=-get<0>(pq.top())){
            tie(a,t,idx)=pq.top();
            pq.pop();
            a=-a;
            park.push({-idx,a,t});
        }
        
        if(park.empty()){
            cur = -get<0>(pq.top());
        }
        else{
            tie(idx,a,t) = park.top();
            park.pop();
            res = max(res,cur-a);
            cur+=t;
        }
    }
    

    cout<<res<<"\n";
}
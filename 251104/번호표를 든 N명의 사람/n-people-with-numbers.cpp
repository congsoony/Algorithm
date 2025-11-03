#include<bits/stdc++.h>
using namespace std;
int n,t;
vector<int> v;
    
bool possible(int mid){

    priority_queue<int,vector<int>,greater<int>> pq;
    int time = 0;
    for(int i=0;i<n;i++){
        if(pq.size()==mid){
            time = pq.top();
            pq.pop();
        }
        pq.push(time+v[i]);
    }
    while(!pq.empty()){
        time = pq.top();
        pq.pop();
    }
    return time<=t;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin>>n>>t;
    v.resize(n);
    for(int i =0;i<n;i++)cin>>v[i];
    int l=1,r=1e9;
    int res = 1e9;
    while(l<=r){
        int mid = (l+r)/2;
        if(possible(mid)){
            r=mid-1;
            res = min(res,mid);
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<"\n";

}
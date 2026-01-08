#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> num(50001);
    priority_queue<int,vector<int>,greater<int>> pq;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        pq.push(v[i]);
        num[v[i]]++;
        sum+=v[i];
    }
    double res = 0;
    for(int i=0;i<n-2;i++){
        sum-=v[i];
        num[v[i]]--;
        while(num[pq.top()]==0){
            pq.pop();
        }
        double total = sum - pq.top();
        res = max(res,total/(n-i-2));
    }
    cout.precision(2);
    cout<<fixed;
    cout<<res<<"\n";
}
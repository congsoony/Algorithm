#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &a:v)cin>>a;
    sort(v.begin(),v.end());
    long long res = 0;
    int l=0,r=n-1;
    while(l<r){
        if(v[l]+v[r]>k){
            r--;
        }
        else{
            res+=r-l;
            l++;
        }
    }
    cout<<res<<"\n";
}
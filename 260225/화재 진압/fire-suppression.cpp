#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(int &a:v1)cin>>a;
    for(int &a:v2)cin>>a;

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int l =0;
    int res = 0;
    for(int i =0;i<n;i++){
        
        while(l+1<m&&abs(v1[i]-v2[l]) >abs(v1[i]-v2[l+1])){
            l++;
        }
        res = max(res,abs(v1[i]-v2[l]));
    }
    cout<<res<<"\n";
}
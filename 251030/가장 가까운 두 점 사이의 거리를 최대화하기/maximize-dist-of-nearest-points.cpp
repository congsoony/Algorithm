#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    vector<int> v;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back(a);
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    int l =1,r=4;
    int res = 0;
    while(l<=r){
        int mid= (l+r)/2;
        int pre =v[0];
        int cnt = 1;
        for(int i=1;i<v.size();i++){
            if(v[i]-pre>=mid){
                pre = pre+mid;
                cnt++;
            }
        }
        if(cnt>=n){
            l=mid+1;
            res = max(res,mid);
        }
        else{
            r =mid-1;
        }
    }
    cout<<res<<"\n";
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int l = 0;
    int res = 0;
    int mx = v[0];
    int mn = v[0];
    vector<int> ans;
    for(int i =1;i<n;i++){
        if(abs(mx-v[i])>k || abs(mn-v[i])>k){
            if(i-1 >l){
                ans.push_back(i-l);
            }
            mx = mn = v[i];
            l=i;
        }
        else{
            mx= max(mx,v[i]);
            mn = min(mn,v[i]);
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());
    cout<<ans[0]+ans[1]<<"\n";
}
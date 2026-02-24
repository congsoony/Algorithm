#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    vector<int> v(n),pre(n),suf(n);
    for(int i =0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int l = 0;

    for(int i = 0;i<n;i++){
        while(v[i]-v[l]>k)l++;
        int len = i-l+1;
        pre[i] = max((i ? pre[i - 1] : 0), len);
    }
    int r = n-1;
    for(int i = n-1;i>=0;i--){
        while(v[r]-v[i]>k)r--;
        int len = r-i+1;
        suf[i] = max((i+1<n)?suf[i+1]:0,len);
    }

    int res = 0;
    for(int i = -1;i<n;i++){
        int left = (i>=0)?pre[i]:0;
        int right = (i+1<n)?suf[i+1]:0;
        res = max(res,left+right);
    }
    cout<<res<<"\n";
}
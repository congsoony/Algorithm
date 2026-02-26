#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<int> v1(n+2),v2(m+2);
    for(int i=1;i<=n;i++) cin>>v1[i];
    for(int i=1;i<=m;i++) cin>>v2[i];

    vector<int>pre(m+2,1e9),suf(m+2,-1e9);
    pre[0]=0;
    suf[m+1]=n+1;
    int l=1;
    for(int i =1;i<=m;i++){
        while(l<=n&&v1[l]!=v2[i])l++;
        if(l>n)break;
        pre[i]=l++;
    }
    int r = n;
    for(int i =m;i>=1;i--){
        while(r>=1&&v1[r]!=v2[i])r--;
        if(r<1)break;
        suf[i]=r--;
    }
    int res =0;
    for(int i=1;i<=m;i++){
        if(pre[i-1]<suf[i+1])res++;
    }
    cout<<res<<"\n";
}
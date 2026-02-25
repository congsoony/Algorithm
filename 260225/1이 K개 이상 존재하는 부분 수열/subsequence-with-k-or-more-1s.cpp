#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    int num[5]={0};
    for(int &i:v)cin>>i;
    int l = 0;
    int res = 1e9;
    for(int i =0;i<n;i++){
        num[v[i]]++;
        while(num[1]==k){
            res = min(res,i-l+1);
            num[v[l++]]--;
        }
    }
    cout<<(res==1e9?-1:res)<<"\n";
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &i:v)cin>>i;
    unordered_map<int,int> num;
    int l=0;
    int res = 0;
    for(int i =0;i<n;i++){
        num[v[i]]++;
        while(num[v[i]]>k)num[v[l++]]--;
        res = max(res,i-l+1);
    }
    cout<<res<<"\n";
}
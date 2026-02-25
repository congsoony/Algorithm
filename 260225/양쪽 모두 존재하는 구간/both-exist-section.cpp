#include<bits/stdc++.h>
using namespace std;

int main() {
    int res = 1e9;
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int &i:v)cin>>i;

    unordered_map<int,int> num;
    int l=0;
    for(int i =0;i<n;i++){
        num[v[i]]++;
        while(num.size()==m){
            res = min(res,i-l+1);
            num[v[l]]--;
            if(num[v[l]]==0)num.erase(v[l]);
            l++;
        }
    }
    cout<<(res==1e9?-1:res)<<"\n";
}
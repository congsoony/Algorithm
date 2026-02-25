#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    int res = 1e9;
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    
    unordered_map<int,int> num,outside;
    for(int &i:v){
        cin>>i;
        outside[i]++;
    }

    int l=0;
    for(int i =0;i<n;i++){
        num[v[i]]++;
        outside[v[i]]--;
        if(outside[v[i]]==0){
            outside.erase(v[i]);
        }
        while(num.size()==m){
            if(outside.size()==m)
                res = min(res,i-l+1);
            num[v[l]]--;
            outside[v[l]]++;
            if(num[v[l]]==0)num.erase(v[l]);
            l++;
        }
    }
    cout<<(res==1e9?-1:res)<<"\n";
}
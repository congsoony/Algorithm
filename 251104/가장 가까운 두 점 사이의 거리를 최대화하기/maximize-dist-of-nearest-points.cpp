#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<pair<int,int>>v;
int main() {
    freopen("input.txt","r",stdin);
    cin>>n;
    v.resize(n);
    for(int i =0;i<n;i++)cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());

    int l=1,r = 1e9;
    int res = 0;
    while(l<=r){
        int mid = (l+r)/2;
        
        int last = -1e9;
        int flag = true;
        for(int i=0;i<v.size();i++){
            int p = max(v[i].first,last+mid);
            if(p>v[i].second){
                flag=false;
                break;
            }
            last = p;
        }
        if(!flag){
            
            r=mid-1;
        }
        else{
            l=mid+1;
            res = max(res,mid);
        }
    }
    cout<<res<<"\n";
}
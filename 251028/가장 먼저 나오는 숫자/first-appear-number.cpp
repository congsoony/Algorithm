#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];   
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        
        if(binary_search(v.begin(),v.end(),t))
            cout<<lower_bound(v.begin(),v.end(),t)-v.begin()+1<<"\n";
        else
            cout<<-1<<"\n";
    }
}
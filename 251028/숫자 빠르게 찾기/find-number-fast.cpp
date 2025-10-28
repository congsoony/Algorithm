#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i =0;i<n;i++)cin>>v[i];
    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        if(binary_search(v.begin(),v.end(),t)){
            cout<<lower_bound(v.begin(),v.end(),t)-v.begin() +1<<"\n";
        }
        else
            cout<<-1<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    n*=2;
    vector<int> v(n),p(n,1);
    for(int i =0;i<n;i++)cin>>v[i];
    for(int i =0;i<n/2;i++)p[i]=0;
    int res =1e9;
    do{
        int sum[2]={0};
        for(int i =0;i<n;i++){
            sum[p[i]]+=v[i];  
        }
        res = min(res,abs(sum[0]-sum[1]));
    }while(next_permutation(p.begin(),p.end()));
    cout<<res<<"\n";

}
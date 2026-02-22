#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n),num(1e5+1);
    for(int &i:v)cin>>i;
    int res = 1;
    int j =0;
    num[v[0]]=1;
    for(int i =1;i<n;i++){
        while(num[v[i]]){
            num[v[j]]=0;
            j++;
        }
        num[v[i]]=1;
        res = max(res,i-j+1);
    }
    cout<<res<<"\n";
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>v(n),v2(k);
    for(int &a:v)cin>>a;
    for(int &a:v2)cin>>a;
    string res = "No";
    int j = 0;

    for(int i =0;i<n;i++){
        if(v[i]==v2[j])
            j++;
        if(j==k){
            res = "Yes";
            break;
        }
    }
    cout<<res<<"\n";
}
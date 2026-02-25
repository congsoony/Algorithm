#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int alpha[255]={0};
    int l =0;
    int res = 0;
    for(int i =0;i<s.size();i++){
        while(alpha[s[i]]){
            alpha[s[l++]]=0;
        }
        alpha[s[i]]=1;
        res = max(res,i-l+1);
    }
    cout<<res<<"\n";
}
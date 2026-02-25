#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin>>s>>k;
    map<int,int> alpha;
    int l=0;
    int res = 0;
    for(int i =0;i<s.size();i++){
        alpha[s[i]]++;
        while(alpha.size()>k){
            if(--alpha[s[l]]==0){
                alpha.erase(s[l]);
            }
            l++;
        }
        res = max(res,i-l+1);
    }
    cout<<res<<"\n";
}
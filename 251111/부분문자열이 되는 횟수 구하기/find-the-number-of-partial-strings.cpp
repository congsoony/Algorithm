#include <bits/stdc++.h>
using namespace std;
string s1,s2;
vector<int> v;
int possible(int mid){
    string s;
    vector<int> check(s1.size());
    for(int i =0;i<mid;i++){
        check[v[i]-1]=1;
    }
    for(int i =0;i<s1.size();i++)if(check[i]==0)s+=s1[i];
    int j =0;
    for(int i=0;i<s.size();i++){
        if(s[i]==s2[j])
            j++;
        if(j==s2.size())return true;
    }
    return false;
}
int main() {
    cin>>s1;
    cin>>s2;
    v = vector<int>(s1.size());
    for(int i =0;i<s1.size();i++)cin>>v[i];
    int l=1,r=s1.size();
    int res =0;

    while(l<=r){
        int mid = (l+r)/2;
        if(possible(mid)){
            res = max(mid+1,res);
            l=mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout<<res<<"\n";
}
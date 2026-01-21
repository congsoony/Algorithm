#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    // 입출력 속도 향상
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),[&](pair<int,int>&a, pair<int,int>&b)->int{
        return a.second<b.second;
    });
    int cnt= 1;
    int before = v[0].second;
    for(int i=1;i<n;i++){
        if(before<=v[i].first){
            cnt++;
            before = v[i].second;
        }
    }
    cout<<v.size()-cnt<<"\n";
}
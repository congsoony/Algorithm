#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>arr;
int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    arr = vector<vector<int>>(n,vector<int>(n));

    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int res = 0;
    for(int i =0;i<n;i++){
        int cnt = 1;
        for(int j =1;j<n;j++){
            if(arr[i][j-1]==arr[i][j]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=m){
                break;
            }
        }
        res+=cnt>=m;

    }
    for(int j =0;j<n;j++){
        int cnt = 1;
        for(int i =1;i<n;i++){
            if(arr[i-1][j]==arr[i][j]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=m){
                break;
            }
        }
        res+=cnt>=m;
    }
    
    cout<<res<<"\n";
    
    
}
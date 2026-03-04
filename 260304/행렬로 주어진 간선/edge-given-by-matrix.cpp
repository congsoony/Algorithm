#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    cin>>n;
    vector<vector<int>> w(n+1,vector<int>(n+1));
    
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    for(int i =1;i<=n;i++)w[i][i]=1;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                w[i][j]|=w[i][k] &w[k][j];
            }
        }
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cout<<w[i][j]<<" ";
        }
        cout<<"\n";
    }


}
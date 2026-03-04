#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    cin>>n>>m;
    vector<vector<int>> w(n+1,vector<int>(n+1));
    for(int i =0;i<m;i++){
        int a,b;
        cin>>a>>b;
        w[a][b]=1; 
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
        int res =-1;
        for(int j =1;j<=n;j++){
            res+=w[i][j]+w[j][i];
        }
        cout<<n-res<<"\n";
    }


}
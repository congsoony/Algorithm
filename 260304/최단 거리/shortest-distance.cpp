#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    cin>>n>>m;
    vector<vector<int>> w(n+1,vector<int>(n+1,1e9));
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                w[i][j]= min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    for(int i =0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cout<<w[a][b]<<"\n";
    }

    
    

}
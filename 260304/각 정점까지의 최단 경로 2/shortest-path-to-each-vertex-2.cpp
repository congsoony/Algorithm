#include <bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    cin>>n>>m;
    vector<vector<int>> w(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++)w[i][i]=0;
    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int mn = min(w[a][b],c);
        w[a][b]=mn;    
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                w[i][j]= min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cout<<(w[i][j]==1e9?-1:w[i][j])<<" ";
        }
        cout<<"\n";
    }


}
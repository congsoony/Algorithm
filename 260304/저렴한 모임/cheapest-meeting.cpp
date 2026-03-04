#include <bits/stdc++.h>
using namespace std;
int n,m,v1,v2,e;
int main() {
    cin>>n>>m;
    cin>>v1>>v2>>e;
    vector<vector<long long>> w(n+1,vector<long long>(n+1,1e15));
    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b]=w[b][a]=c;
    }
    for(int i =1;i<=n;i++)w[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                w[i][j]= min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    
    long long res =w[v1][e]+w[v2][e];
    for(int i =1;i<=n;i++){
        if(i==e)continue;
        res = min(res,w[v1][i]+w[v2][i]+w[i][e]);
    }
    
    cout<<(res<=1e15?res:-1)<<"\n";

}
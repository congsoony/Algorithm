#include <bits/stdc++.h>
using namespace std;
int n,m,p,q;
int main() {
    cin>>n>>m>>p>>q;
    vector<vector<long long>> w(n+1,vector<long long>(n+1,1e15));
    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b]=c;
    }
    for(int i =1;i<=n;i++)w[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                w[i][j]= min(w[i][j],w[i][k]+w[k][j]);
            }
        }
    }
    
    long long res = 0;
    int cnt = 0;

    for(int i =0;i<q;i++){
        int a,b;
        cin>>a>>b;
        long long cost = 1e15;
        for(int j =1;j<=p;j++){
            if(w[a][j]+w[j][b]<1e15){
                cost = min(cost,w[a][j]+w[j][b]);
            }
        }
        if(cost!=1e15){
            res +=cost;
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    cout<<res<<"\n";
    

}
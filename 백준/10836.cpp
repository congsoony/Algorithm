#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n;
vector<ll> v;
vector<vector<ll>>arr;
void input(){
    cin>>m>>n;
    v =vector<ll>(m*2-1,1);
    int a,b,c;
    for(int i =0;i<n;i++){
        cin>>a>>b>>c;
        b+=a;
        c+=b;
        for(int j=a;j<b;j++)v[j]++;
        for(int j=b;j<c;j++)v[j]+=2;
    }
}

void solve(){
    arr= vector<vector<ll>>(m,vector<ll>(m));
    for(int i =m-1,j=0;i>=0;i--,j++)arr[i][0]=v[j];
    for(int i =1,j=m;i<m;i++,j++)arr[0][i]=v[j];
    
    
    for(int i =0;i<m;i++){
        for(int j =0;j<m;j++){
            if(i==0||j==0)
                cout<<arr[i][j]<<" ";
            else{
                arr[i][j]=max({arr[i-1][j-1],arr[i-1][j],arr[i][j-1]});
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}

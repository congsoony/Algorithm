#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll>x,y;
vector<tuple<ll,ll,ll>>v;
vector<int> parent;
int n;
double e;
void input(){
    cin>>n;
    x=y=vector<ll>(n);
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>y[i];
    cin>>e;
}
int find(int idx){
    if(idx==parent[idx])return idx;
    return parent[idx]=find(parent[idx]);
}
bool merge(int a,int b){
    a =find(a);
    b =find(b);
    if(a==b)return false;
    parent[b]=a;
    return true;
}
void solve(){
    v.clear();
    parent = vector<int>(n);
    for(int i=0;i<n;i++)parent[i]=i;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            v.push_back({(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),i,j});
        }
    }
    sort(v.begin(),v.end());
    double sum=0;
    for(auto[cost,node1,node2]:v){
        
        if(merge(node1,node2))
            sum+=cost;
    }
    cout<<(ll)round(sum*e)<<"\n";
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        cout<<"#"<<i<<" ";
        input();
        solve(); 
    }
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree,v;
int n,m;
vector<tuple<int,int,int>> tv;
void input(){
    cin>>n;
    tree = vector<ll>(n*4);
    v= vector<ll>(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        tv.push_back({a,b,c});
    }
}
ll init(int s=0,int e=n-1,int node=1){
    if(s==e)return tree[node]=v[s]%2;
    int mid= (s+e)/2;
    return tree[node]=init(s,mid,node*2)+init(mid+1,e,node*2+1);
}
void update(int p,int val,int s=0,int e=n-1,int node=1){
    if(!(s<=p&&p<=e))return;
    if(s==e){
        tree[node]=val%2;
        return;
    }
    int mid =(s+e)/2;
    update(p,val,s,mid,node*2);
    update(p,val,mid+1,e,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
ll query(int l,int r,int s=0,int e=n-1,int node=1){
    if(l>e ||r<s)return 0;
    if(l<=s&&e<=r){
        return tree[node];
    }
    int mid = (s+e)/2;
    return query(l,r,s,mid,node*2)+query(l,r,mid+1,e,node*2+1);
}
void solve(){
    init();
    for(int i = 0;i<tv.size();i++){
        int a,b,c;
        tie(a,b,c)=tv[i];
        if(a==1){
            update(b-1,c);
        }
        else if(a==2){
            cout<<c-b+1-query(b-1,c-1)<<"\n";
        }
        else{
            cout<<query(b-1,c-1)<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();

}

/* 비재귀 Segtree
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree;
int n,m;
vector<tuple<int,int,int>> tv;
void input(){
    cin>>n;
    tree = vector<ll>(n*2);
    for(int i =0;i<n;i++){
        cin>>tree[i+n];
        tree[i+n]%=2;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        tv.push_back({a,b,c});
    }
}
void update(int p,int val){
    for(tree[p+=n]=val%2;p>1;p>>=1){
        tree[p>>1]=tree[p]+tree[p^1];
    }
}
ll query(int l,int r){
    ll res =0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1)res+=tree[l++];
        if(r&1)res+=tree[--r];
    }
    return res;
}
void solve(){
    for(int i =n-1;i>0;i--)tree[i]=tree[i<<1]+tree[i<<1|1];
    for(int i = 0;i<tv.size();i++){
        int a,b,c;
        tie(a,b,c)=tv[i];
        if(a==1){
            update(b-1,c);
        }
        else if(a==2){
            cout<<c-b+1-query(b-1,c-1)<<"\n";
        }
        else{
            cout<<query(b-1,c-1)<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();

}
*/
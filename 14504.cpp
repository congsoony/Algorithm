#include<bits/stdc++.h>
using namespace std;
#define ll long long
//제곱근 분할법 sqrt Decomposition
int n,m;
vector<ll> arr;
vector<vector<ll>>bucket;
vector<tuple<ll,ll,ll,ll>> iv;
int sqrtN;
void input() {
	cin >> n;
	arr=vector<ll>(n+1);
   for(int i =0;i<n;i++)cin>>arr[i];
   cin>>m;
   int a,b,c,d=0;
   for(int i =0;i<m;i++){
      cin>>a>>b>>c;
      if(a==1)cin>>d;
      iv.push_back({a,b,c,d});
   }
}
void init(){
   sqrtN = sqrt(n);
   bucket = vector<vector<ll>>(n+1);
   for(int i=0;i<n;i++){
      bucket[i/sqrtN].push_back(arr[i]);
   }
   for(int i =0;i<=sqrtN;i++)sort(bucket[i].begin(),bucket[i].end());
}
void update(int x,ll val){
   int idx = x/sqrtN;
   int bidx = lower_bound(bucket[idx].begin(),bucket[idx].end(),arr[x])-bucket[idx].begin();
   bucket[idx].erase(bucket[idx].begin()+bidx);

   arr[x]=val;
   bidx = lower_bound(bucket[idx].begin(),bucket[idx].end(),val)-bucket[idx].begin();
   bucket[idx].insert(bucket[idx].begin()+bidx,val);
}

ll query(int l,int r,ll k){
   ll ret = 0;
   while(l%sqrtN!=0 && l<=r){
      ret+=arr[l++]>k;
   }
   while((r+1)%sqrtN!=0&&l<=r){
      ret+=arr[r--]>k;
   }
   while(l<=r){
      int idx = l/sqrtN;
      ret+=bucket[idx].end()-upper_bound(bucket[idx].begin(),bucket[idx].end(),k);
      l+=sqrtN;
   }
   return ret;
}
void solve() {
   init();
   for(auto[a,b,c,d]:iv){
      if(a==1){
         cout<<query(b-1,c-1,d)<<"\n";
      }
      else{
         update(b-1,c);
      }
   }

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	input();
   solve();

}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//제곱근 분할법 sqrt Decomposition
int n,m;
vector<ll> arr;
vector<ll>bucket[100];
vector<tuple<ll,ll,ll,ll>> iv;
int sqrtN;
void input() {
	cin >> n;
   arr = vector<ll>(n*2);
   for(int i = 0;i<n;i++)cin>>arr[i];
}

void init(){
   sqrtN = 1200;
   for(int i =0;i<n;i++)bucket[i/sqrtN].push_back(arr[i]);
   for(int i =0;i<100;i++)sort(bucket[i].begin(),bucket[i].end());
}
void update(int x,ll val){
   int idx = x/sqrtN;
   bucket[idx].erase(lower_bound(bucket[idx].begin(),bucket[idx].end(),arr[x]));
   arr[x]=val;
   bucket[idx].insert(lower_bound(bucket[idx].begin(),bucket[idx].end(),val),val);
}
ll query(int l,int r,ll val){
   ll res = 0;
   while(l%sqrtN!=0 && l<=r)res+=arr[l++]>val;
   while((r+1)%sqrtN!=0&&l<=r)res+=arr[r--]>val;
   while(l<=r){
      int idx = l/sqrtN;
      res+= bucket[idx].end()-upper_bound(bucket[idx].begin(),bucket[idx].end(),val);
      l+=sqrtN;
   }
   return res;
}

void solve() {
   init();
   cin>>m;
   ll a,b,c,d;
   for(int i =0;i<m;i++){
      cin>>a>>b>>c;
      if(a==2){
         cin>>d;
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
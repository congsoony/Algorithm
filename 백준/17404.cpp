#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> arr[3];
vector<vector<ll>>dp[3];
void input() {
	cin>>n;
   arr[0]=arr[1]=arr[2] = vector<ll>(n);
   for(int i =0;i<n;i++)cin>>arr[0][i]>>arr[1][i]>>arr[2][i];
   dp[0]=dp[1]=dp[2] = vector<vector<ll>>(3,vector<ll>(n,1e15));
}


ll dfs(int start,int color ,int cur){
   
   if(cur==n-1){
      return start!=color?arr[color][cur]:1e15;
   }
   ll &cache = dp[start][color][cur];
   if (cache!=1e15)return cache;
   int left =(color-1 + 3)%3;
   int right = (color+1)%3;
   return cache=min(dfs(start,left,cur+1),dfs(start,right,cur+1))+arr[color][cur];
}


void solve() {


   cout<<min({dfs(0,0,0),dfs(1,1,0),dfs(2,2,0)})<<"\n";


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	input();
   solve();
 
}
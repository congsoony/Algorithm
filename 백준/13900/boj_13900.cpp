#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> v,dp;
void input() {
    cin >> n;
    v.resize(n+1);
    dp = v;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        dp[i] = v[i] + dp[i - 1];
    }
}
void solve() {
    ll res = 0;
    for (int i = 1; i < n; i++) 
        res += v[i] * (dp[n] - dp[i]);
    cout << res << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
 
}
 
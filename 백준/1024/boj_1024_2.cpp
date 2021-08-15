#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, l;
void input() {
    cin >> n >> l;
}
ll Summ(ll t) {
    return (t * (t - 1)) / 2L;
}
void solve() {
    for (ll L = l; L <= 100; L++) {
        ll sum = n - Summ(L);
        if (sum % L == 0&&sum/L>=0) {
            for (ll i = sum / L; i < L + (sum / L); i++) {
                cout << i << " ";
            }
            return;
        }
    }
    cout << -1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}

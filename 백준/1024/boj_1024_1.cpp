#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, l;
void input() {
    cin >> n >> l;
}
void solve() {
    for (ll L = l; L <= 100; L++) {
        for (ll a = 0;; a++) {
            if (n == (L * a + (L * (L - 1)) / 2)) {
                for (ll i = 0; i < L; i++)
                    cout << a + i << " ";
                return;
            }
            else if (n < (L * a + (L * (L - 1)) / 2))
                break;
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
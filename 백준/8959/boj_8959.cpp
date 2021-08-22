//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
string s;
void input() {
    int n;
    cin >> n;
    cin >> s;
}
void solve() {
    regex re(R"(\d+)");
    auto it = sregex_iterator(s.begin(), s.end(), re);
    long long res = 0;
    while (it != sregex_iterator()) {
        res += stoll(it->str());
        it++;
    }
    cout << res << "\n";
 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    input();
    solve();
}
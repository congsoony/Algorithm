//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
void input() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
 
}
void solve() {
    string p1 = R"((\w+)://([\w\.-]+):?(\d*)/?(\S+)*)";
    vector<string> sv = { "Protocol = ","Host     = ","Port     = ","Path     = " };
 
    for (int i = 0; i < v.size(); i++) {
        smatch match;
        regex_search(v[i], match, regex(p1));
        cout << "URL #" << i + 1 << "\n";
        for (int j = 1; j <= 4; j++) {
            cout << sv[j - 1] << (match[j].str().empty() ? "<default>" : match[j].str()) << "\n";
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
 
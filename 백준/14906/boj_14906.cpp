//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n;
bool isslump(string s) {
    return regex_match(s, regex(R"(([DE]F+)+G)"));
}
bool isslimp(string s) {
    string patterns[] = { R"(AB.+C)",R"(A.+C)" };
    smatch match;
    if (s.size() >= 3) {
        if (regex_search(s, match, regex(patterns[0]))) {
            string t = match[0];
            return isslimp(t.substr(2, t.size() - 3));
        }
        if (regex_search(s, match, regex(patterns[1]))) {
            string t = match[0];
            return isslump(t.substr(1, t.size() - 2));
        }
    }
    return s == "AH";
}
void input() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
 
}
void print(string s) {
    for (int i = 0; i < s.size(); i++) {
        string sli = s.substr(0, i);
        string slu = s.substr(i);
        if (isslimp(sli) && isslump(slu)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
void solve() {
    cout << "SLURPYS OUTPUT\n";
    for (string s : v) {
        print(s);
    }
    cout << "END OF OUTPUT\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    input();
    solve();
}
 
 

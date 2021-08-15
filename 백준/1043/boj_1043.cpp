//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> parent,fact;
vector<vector<int>> v;
 
int find(int idx) {
    if (idx == parent[idx])return idx;
    return parent[idx] = find(parent[idx]);
}
void Union(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
    if (fact[a] || fact[b])
    {
        fact[a] = fact[b] = true;
    }
}
 
void input() {
    cin >> n >> m;
    parent.resize(n + 1);
    fact.resize(n + 1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        fact[num] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> k;
        vector<int> v2(k);
        for (int j = 0; j < k; j++) {
            cin >> v2[j];
        }
        v.push_back(v2);
    }
}
void solve() {
    int res = 0;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < v[i].size(); j++) {
            Union(v[i][j - 1], v[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int flag = 1;
        for (int j = 0; j < v[i].size(); j++) {
            if (fact[find(v[i][j])])
            {
                flag = false;
                break;
            }
        }
        res += flag;
    }
    cout << res << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
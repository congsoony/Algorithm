#include <bits/stdc++.h>
using namespace std;
int n, k;
int board[15][15];

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;) {
            int length = 0;
            for (int k = j; k <n&&board[i][k]==1; k++) {
                length++;
            }
            if (length == k)cnt++;
            if (length)
                j += length;
            else
                j++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;) {
            int length = 0;
            for (int k = j; k < n && board[k][i] == 1; k++) {
                length++;
            }
            if (length == k)cnt++;
            if (length)
                j += length;
            else
                j++;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        input();
        cout << "#" << i << " ";
        solve();
    }
}
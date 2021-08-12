//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
char board[20][20];
int n;
int dy[4] = { -1,0,1,1 };
int dx[4] = { 1,1,1,0 };
void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
}
bool isrange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}
int path(int y, int x, int dir) {
    if (!isrange(y, x)) return 0;
    if (board[y][x] == '.') return 0;
    return 1 + path(y + dy[dir], x + dx[dir], dir);
}
void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                if (path(i, j, k) >= 5) {
                    cout << "YES" << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO" << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
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
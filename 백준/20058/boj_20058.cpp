//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
 
int n, q;
vector<vector<int>> board;
vector<int> lv;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int check[64][64];
 
void input() {
    cin >> n >> q;
    board = vector<vector<int>>((1 << n), vector<int>(1 << n));
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            cin >> board[i][j];
        }
    }
    lv.resize(q);
    for (int i = 0; i < q; i++)
        cin >> lv[i];
 
}
 
void rotate2(int y,int x,int size,vector<vector<int>> &temp) {
    for (int i = y,j2=x+size-1; i < y + size; i++,j2--) {
        for (int j = x,i2=y; j < x + size; j++,i2++) {
            board[i2][j2] = temp[i][j];
        }
    }
}
 
void rotate(int l) {
    vector<vector<int>> temp = board;
    for (int i = 0; i < (1 << n); i+=(1<<l)) {
        for (int j = 0; j < (1 << n); j += (1 << l)) {
            rotate2(i, j, 1 << l, temp);
        }
    }
}
bool isrange(int y, int x) {
    return 0 <= y && y < (1 << n) && 0 <= x && x < (1 << n);
}
 
int dfs(int y, int x) {
    if (!isrange(y, x))return 0;
    if (check[y][x]||board[y][x]==0)return 0;
    check[y][x] = 1;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        res += dfs(y + dy[i], x + dx[i]);
    }
    return res;
}
void solve() {
    for (int l : lv) {
        rotate(l);
        vector<vector<int>> temp = board;
 
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < (1 << n); j++) {
                int cnt = 0;
                for (int k = 0; k < 4&&board[i][j]; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (!isrange(ny, nx))continue;
                    if (temp[ny][nx])cnt++;
                }
                if (cnt < 3&&board[i][j])
                    board[i][j]--;
            }
        }
    }
    
    int res = 0;
    int res2 = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            res += board[i][j];
            res2 = max(res2, dfs(i, j));
        }
    }
    cout << res << "\n";
    cout << res2 << "\n";
 
 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    input();
    solve();
 
}
 
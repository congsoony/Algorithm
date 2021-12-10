#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m;
int board[101][101];
int sy, sx, sdir;
int fy, fx, fdir;
void change(int& dir) {
    if (dir == 4)
        dir = 0;
    else if (dir == 1)
        dir = 1;
    else if (dir == 3)
        dir = 2;
    else if (dir == 2)
        dir = 3;
}
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cin >> sy >> sx >> sdir;
    cin >> fy >> fx >> fdir;
    sy--, sx--, fy--, fx--;
    change(sdir);
    change(fdir);
}
 
bool isrange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}
int bfs() {
    int check[100][100][4] = { 0 };
    queue<tuple<int, int, int, int>> q;
    q.push({ sy,sx,sdir ,0 });
    check[sy][sx][sdir] = 1;
    while (!q.empty()) {
        int y, x, dir, cnt;
        tie(y, x, dir, cnt) = q.front();
        q.pop();
        if (y == fy && x == fx && dir == fdir)
            return cnt;
        for (int i = 1; i <= 3; i++) {
            int ny = y + dy[dir] * i;
            int nx = x + dx[dir] * i;
            if (!isrange(ny, nx))break;
            if (board[ny][nx])break;
            if (check[ny][nx][dir] == 0) {
                q.push({ ny,nx,dir,cnt + 1 });
                check[ny][nx][dir] = 1;
            }
        }
        for (int i : {1, -1}) {
            int ndir = (4 + dir + i) % 4;
            if (check[y][x][ndir] == 0) {
                q.push({ y,x,ndir,cnt + 1 });
                check[y][x][ndir] = 1;
            }
        }
    }
    return -1;
}
void solve() {
    cout << bfs() << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
 
    input();
    solve();
}
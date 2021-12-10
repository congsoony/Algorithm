#include<bits/stdc++.h>
using namespace std;
char board[1500][1500];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
bool check[1500][1500];
vector<pair<int, int>> v;
int n, m;
queue<pair<int, int>> water;
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') {
                v.push_back({ i,j });
                board[i][j] = '.';
                water.push({ i,j });
            }
            else if (board[i][j] == '.') {
                water.push({ i,j });
            }
        }
    }
}
 
bool isrange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}
 
int bfs() {
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push(v[0]);
    check[v[0].first][v[0].second] = 1;
    while (true) {
        bool flag = false;
        queue<pair<int, int>> nq;
        while (!q.empty()) {
            int y, x;
            tie(y, x) = q.front();
            q.pop();
            if (y == v[1].first && x == v[1].second)
                return cnt;
 
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (isrange(ny, nx)&&check[ny][nx]==0) {
                    check[ny][nx] = true;
                    if (board[ny][nx] == '.') {
                        q.push({ ny,nx });
                    }
                    else if (board[ny][nx] == 'X')
                        nq.push({ ny,nx });
                    
                }
            }
        }
        int watersize = water.size();
        while (watersize--) {
            int y, x;
            tie(y, x) = water.front();
            water.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (isrange(ny, nx) && board[ny][nx] == 'X') {
                    board[ny][nx] = '.';
                    water.push({ ny,nx });
                }
            }
        }
        q = nq;
        cnt++;
    }
    return cnt;
}
void solve() {
    cout << bfs() << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vvvi v<vvi>
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n;
bool isrange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}
int bfs(vvi& board) {
    n = board.size();
    vvvi visit(4, vvi(n, vi(n)));
    queue<tuple<int, int, int, int>> q;
    q.push({ 1,0,0,0 });
    visit[1][0][0] = 1;
    int res = 0;
    while (!q.empty()) {
        int dir, y1, x1, cnt, y2, x2;
        tie(dir, y1, x1, cnt) = q.front();
        q.pop();
        tie(y2, x2) = make_tuple(y1 + dy[dir], x1 + dx[dir]);
        res = cnt;
        if ((y1 == n - 1 && x1 == n - 1) || (y2 == n - 1 && x2 == n - 1)) return cnt;
        //좌우상하 이동
        for (int i = 0; i < 4; i++) {
            int ny1, nx1, ny2, nx2;
            tie(ny1, nx1, ny2, nx2) = make_tuple(y1 + dy[i], x1 + dx[i], y2 + dy[i], x2 + dx[i]);
            if (!isrange(ny1, nx1) || !isrange(ny2, nx2))continue;
            if (visit[dir][ny1][nx1] || board[ny1][nx1] || board[ny2][nx2])continue;
            q.push({ dir,ny1,nx1,cnt + 1 });
            visit[dir][ny1][nx1] = 1;
        }
        //회전
        int r[2] = { 1,3 };
        for (int i : r) {
            int ndir = (dir + i) % 4;
            int ny1, nx1, ny2, nx2;
            tie(ny1, nx1, ny2, nx2) = make_tuple(y1 + dy[ndir], x1 + dx[ndir], y2 + dy[ndir], x2 + dx[ndir]);
            if (!isrange(ny1, nx1) || !isrange(ny2, nx2))continue;
            //이동이 가능한건지
            if (board[ny1][nx1] || board[ny2][nx2])continue;
            if (visit[ndir][y1][x1] == 0) {
                q.push({ ndir,y1,x1 ,cnt+1});
                visit[ndir][y1][x1] = 1;
            }
            if (visit[ndir][y2][x2] == 0) {
                q.push({ ndir,y2,x2 ,cnt + 1 });
                visit[ndir][y2][x2] = 1;
            }
        }
    }
    return res;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    return bfs(board);
}

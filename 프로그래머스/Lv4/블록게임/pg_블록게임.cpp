//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vvvi v<vvi>
#define pii pair<int,int>
#define vpii v<pii>
#define M 200
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vvi check, Board;
int n;
pii minb[M+1], maxb[M+1];
vpii blocks[M+1];
vi colors(M + 1);
bool isrange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}
void dfs(int y, int x, int color) {
    if (!isrange(y, x))return;
    if (Board[y][x] == 0)return;
    if (check[y][x] || Board[y][x] != color)return;
    check[y][x] = 1;
    for (int i = 0; i < 4; i++)
        dfs(y + dy[i], x + dx[i], color);
    blocks[color].push_back({ y,x });
}
 
 
void fall(vvi& temp) {
    for (int i = 0; i < n; i++) {
        if (temp[0][i] == 0) {
            temp[0][i] = -1;
            int y = 0, x = i;
            int ny = y+dy[2];
            int nx = x + dx[2];
            while (isrange(ny, nx) && temp[ny][nx] == 0) {
                swap(temp[ny][nx], temp[y][x]);
                tie(y, x, ny, nx) = make_tuple(ny, nx, ny + dy[2], nx + dx[2]);
            }
        }
    }
}
bool iserase(int color,vvi& temp) {
    int cnt = 0;
    int h = maxb[color].first - minb[color].first + 1;
    int w = maxb[color].second - minb[color].second + 1;
    for (int i = minb[color].first; i <= maxb[color].first; i++) {
        for (int j = minb[color].second; j <= maxb[color].second; j++) {
            if (temp[i][j] == color || temp[i][j] == -1)
                cnt++;
        }
    }
    return cnt == h * w;
}
void Erase() {
    for (int i = 0; i < M; i++) {
        vvi temp = Board;
        fall(temp);
        fall(temp);
        for (int j = 1;j <= M; j++) {
            if (colors[j] == 0)continue;
            if (iserase(j, temp)) {
                for (int k = 0; k < blocks[j].size(); k++)
                    Board[blocks[j][k].first][blocks[j][k].second] = 0;
                colors[j] = 0;
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    Board = board;
    check = vvi(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dfs(i, j, Board[i][j]);
            colors[Board[i][j]] = 1;
        }
    }
    colors[0] = 0;
 
    for (int i = 1; i <= M; i++) {
        if (colors[i] == 0)continue;
        answer += colors[i];
        minb[i] = blocks[i][0];
        maxb[i] = blocks[i][0];
        for (int j = 0; j < 4; j++) {
            minb[i].first = min(minb[i].first, blocks[i][j].first);
            minb[i].second = min(minb[i].second, blocks[i][j].second);
            maxb[i].first = max(maxb[i].first, blocks[i][j].first);
            maxb[i].second = max(maxb[i].second, blocks[i][j].second);
        }
    }
    Erase();
    for (int i = 1; i <= M; i++) {
        answer -= colors[i];
    }
    return answer;
}

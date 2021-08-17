//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n;
bool isrange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < n; }
void dfs(int y, int x, int color, vvi& board, vvi& visit, vpii& v) {
    if (!isrange(y, x))return;
    if (visit[y][x] || board[y][x] != color)return;
    visit[y][x] = 1;
    //도형들을 찾아 v에 집어넣기
    v.push_back({ y,x });
    for (int i = 0; i < 4; i++)dfs(y + dy[i], x + dx[i], color, board, visit, v);
}
void rotate(vvi& board) {
    //board의 행사이즈과 열사이즈가 바뀜
    vvi temp(board[0].size(), vi(board.size())); 
    for (int i = 0, j2 = board.size() - 1; i < board.size(); i++, j2--) {
        for (int j = 0, i2 = 0; j < board[i].size(); j++, i2++) {
            temp[i2][j2] = board[i][j];
        }
    }
    board = temp;
}
void makeboard(vpii& v, map<int, vector<vvi>>& block) {
    int fy, fx, my, mx;
    tie(fy, fx, my, mx) = { v[0].first,v[0].second,v[0].first,v[0].second };
    for (int i = 1; i < v.size(); i++) {
        fy = max(fy, v[i].first);
        fx = max(fx, v[i].second);
        my = min(my, v[i].first);
        mx = min(mx, v[i].second);
    }
    int height = fy - my + 1;
    int width = fx - mx + 1;
    vvi board(height, vi(width));
    for (int i = 0; i < v.size(); i++) {
        board[v[i].first - my][v[i].second - mx] = 1;
    }
    block[v.size()].push_back(board);
}
bool issame(vvi& board, vvi& board2) {
    for (int i = 0; i < 4; i++) {
        if (board == board2)return true;
        rotate(board2);
    }
    return false;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    n = table.size();
    vvi visit(n, vi(n));
    vvi visit2 = visit;
    map<int, vector<vvi>> block, block2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0 && visit[i][j] == 0) {
                vpii v;
                dfs(i, j, 0, game_board, visit, v);
                makeboard(v, block);
 
            }
            if (table[i][j] && visit2[i][j] == 0) {
                vpii v;
                dfs(i, j, 1, table, visit2, v);
                makeboard(v, block2);
            }
        }
    }
 
    for (auto it : block) {
        int size = it.first;
        for (vvi v : it.second) {
            for (int i = 0; i < block2[size].size(); i++) {
                if (issame(v, block2[size][i])) {
                    block2[size].erase(block2[size].begin() + i);
                    answer += size;
                    break;
                }
            }
        }
    }
    return answer;
}

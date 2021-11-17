//By 콩순이내장고
#include <bits/stdc++.h>
using namespace std;
#define v vector
#define vi v<int>
#define vvi v<vi>
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
char alpha[255] = {};
int n, m;
vvi check[4];
int dfs(int y, int x, int dir,vector<string>&grid) {
    if (check[dir][y][x]) {
        return 0;
    }
    check[dir][y][x] = 1;
    dir = (4 + (dir + alpha[grid[y][x]])) % 4;
    int ny = (n + y + dy[dir]) % n;
    int nx = (m + x + dx[dir]) % m;
    return 1+dfs(ny, nx, dir, grid);
 
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    n = grid.size();
    m = grid[0].size();
    alpha['L'] = -1;
    alpha['R'] = 1;
    check[0] = check[1] = check[2] = check[3] = vvi(n, vi(m));
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (!check[k][i][j])
                    answer.push_back(dfs(i, j, k, grid));
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
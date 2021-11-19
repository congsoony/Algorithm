//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vvvi v<vvi>
int n, m;
vvi board,dirty;
int sy, sx;
int cnt;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void input() {
	cin >> m >> n;
	board= dirty = vvi(n, vi(m));
	char c;
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'o') {
				tie(sy, sx) = { i,j };
			}
			else if (c == 'x') {
				board[i][j] = 1;
			}
			else if (c == '*') {
				board[i][j] = 2;
				dirty[i][j] = cnt++;//더러운칸 순서대로 번호부여
			}
		}
	}
}
bool isrange(int y, int x) {
	return 0 <= y && y < n && 0 <= x && x < m;
}
int bfs() {
	vvvi check(n, vvi(m, vi(1 << cnt)));//더러운개수만큼 경우의수를 만듬
	queue<tuple<int, int, int,int>> q;
	q.push({ sy,sx,0,0 });
	check[sy][sx][0] = 1;
	while (!q.empty()) {
		int y, x, clean, count;
		tie(y, x, clean, count) = q.front();
		q.pop();
		if (board[y][x] == 2) {
			clean |= 1 << dirty[y][x];
		}
		if (clean == (1 << cnt) - 1) {//전부 청소했는지
			return count;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isrange(ny, nx) &&board[ny][nx]!=1&& check[ny][nx][clean] == 0) {
				q.push({ ny,nx,clean,count + 1 });
				check[ny][nx][clean] = 1;
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
	while (true) {
		input();
		if (n == 0 && m == 0)break;
		solve();
	}
}


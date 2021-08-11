//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
int n, m, fuel;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int board[21][21];
int passengers[21][21];
 
//도착지점은 같을수 있음
vector<pair<int, int>> destination;
int sy, sx;
 
void input() {
    cin >> n >> m >> fuel;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    cin >> sy >> sx;
    destination.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        passengers[y1][x1] = i;
        destination[i] = { y2,x2 };
    }
}
 
bool isrange(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= n;
}
bool findbfs(int& distance, int& idx, int& cy, int& cx) {
    queue<pair<int, int>> q;
    q.push({ sy,sx });
    int length = 0;
    bool visit[21][21] = { 0 };
    vector<tuple<int, int, int>> v;//y,x좌표순으로 정렬하고 3번째는 승객의 번호
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
 
            //승객이있는지 택시가 움직이지 않고도 그자리에 승객이 있을수도있음
            if (passengers[y][x]) {
                v.push_back({ y,x,passengers[y][x] });
            }
 
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (isrange(ny, nx) && !board[ny][nx] && !visit[ny][nx]) {
                    q.push({ ny,nx });
                    visit[ny][nx] = 1;
                }
            }
        }
 
        if (!v.empty()) {
            sort(v.begin(), v.end());
            distance = length;
            tie(cy, cx, idx) = v[0];
            return true;
        }
        length++;
    }
    return false;
}
 
bool gobfs(int& distance, int idx, int& cy, int& cx) {
    queue<pair<int, int>> q;
    q.push({ sy,sx });
    int length = 0;
    bool visit[21][21] = { 0 };
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            if (destination[idx].first==y&&destination[idx].second==x) {
                distance = length;
                cy = y;
                cx = x;
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (isrange(ny, nx) && !board[ny][nx] && !visit[ny][nx]) {
                    q.push({ ny,nx });
                    visit[ny][nx] = 1;
                }
            }
        }
        length++;
    }
 
    return false;
}
void solve() {
    for (int i = 1; i <= m; i++) {
        int distance = 0, cy = 0, cx = 0, idx = 0;
 
        if (!findbfs(distance, idx, cy, cx)) {//승객찾기
            fuel = -1;
            break;
        }
        //거리만큼 빼줌
        fuel -= distance;
        //위치 셋팅
        sy = cy;
        sx = cx;
        passengers[sy][sx] = 0;//승객을 태움
        if (fuel < 0)break;//연료부족한지
 
        if (!gobfs(distance, idx, cy, cx)) {//목적지까지 출발
            fuel = -1;
            break;
        }
        if (fuel - distance < 0) {
            fuel = -1;
            break;
        }
        fuel += distance;
        sy = cy;
        sx = cx;
    }
 
    cout << (fuel < 0 ? -1 : fuel) << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    input();
    solve();
 
}
//By 콩순이냉장고
#include <bits/stdc++.h>
using namespace std;
 
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vvvi v<vvi>
int n;
vvi board;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
struct point {
    int y, x;
    bool operator <(point& a) { return this->y < a.y ? true : this->x < a.x; }
    friend bool operator ==(const point& a,const point& b) {
        return a.y == b.y && a.x == b.x;
    }
};
v<point> sv, fv;
void input() {
    cin >> n;
    board = vvi(n, vi(n));
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '1') {
                board[i][j] = 1;
            }
            else if(c=='B') {
                sv.push_back({ i,j });
            }
            else if (c == 'E') {
                fv.push_back({ i,j });
            }
        }
    }
}
bool isgo(int y, int x) {
    if (!(0 <= y && y < n && 0 <= x && x < n)) return false;
    return board[y][x] == 0;
}
int whatshape(vector<point> &vp) {
    for (int i = 0; i < 4; i++) {
        if (vp[1].y - vp[0].y == dy[i] && vp[1].x - vp[0].x == dx[i])
            return i % 2;
    }
    return -1;
}
void maketree(v<point>& vp,int shape) {
    for (int i = 0; i < 3; i += 2) {
        vp[i].y = vp[1].y + dy[(shape + i) % 4];
        vp[i].x = vp[1].x + dx[(shape + i) % 4];
    }
}
v<point> nexttree(v<point>& vp, int idx) {
    v<point> np(3);
    for (int i = 0; i < 3; i++) {
        np[i].y = vp[i].y + dy[idx];
        np[i].x = vp[i].x + dx[idx];
    }
    return np;
}
int bfs() {
    vvvi check(2, vvi(n, vi(n)));
    queue<tuple<int, int, int>> q;
    int shape, y, x;
    tie(shape, y, x) = make_tuple(whatshape(sv), sv[1].y, sv[1].x);
    q.push({ shape,y,x });
    check[shape][y][x] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            int shape, y, x;
            tie(shape, y, x) = q.front();
            q.pop();
            v<point> vp(3);
            vp[1] = { y,x };
            maketree(vp, shape);
            
            if (vp == fv)
                return cnt;
            for (int i = 0; i < 4; i++) {
                v<point> np = nexttree(vp, i);
                bool flag = true;
                for (int j = 0; j < 3; j++)
                    flag &= isgo(np[j].y, np[j].x);
                if (flag == false)continue;
                if (check[shape][np[1].y][np[1].x])continue;
                check[shape][np[1].y][np[1].x] = 1;
                q.push({ shape,np[1].y,np[1].x });
            }
            
            //회전
            int arr[] = { 1,3 };
            int gocnt = 0;
            int nshape = (shape + 1) % 2;
            for (int r : arr) {
                int ndir = (shape + r) % 4;
                v<point> np = nexttree(vp, ndir);
                bool flag = true;
                for (int i = 0; i < 3; i++) {
                    flag &= isgo(np[i].y, np[i].x);
                }
                gocnt += flag;
            }
            if (gocnt == 2 && check[nshape][vp[1].y][vp[1].x] == 0) {
                q.push({ nshape,vp[1].y,vp[1].x });
                check[nshape][vp[1].y][vp[1].x] = 1;
            }
        }
        cnt++;
    }
    return 0;
}
void solve() {
    cout << bfs() << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    input();
    solve();
 
 
}
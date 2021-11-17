//By 콩순이냉장고
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m,Max;
vector<ll> v;
void input() {
    cin >> n >> m;
    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        Max = max(v[i], Max);
    }
}
void solve() {
    if (n <= m) {
        cout << n << "\n";
        return;
    }
    n -= m;//0초에 m명 모두태우고 시작
    ll left = 0;
    ll right = Max * n;
    ll Time = right;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll sum = 0;
        for (int i = 0; i < m; i++) {
            sum += mid / v[i];
        }
        if (sum >= n) {//n명을 전부 태울수있는 최소시간구하기
            right = mid - 1;
            Time = min(mid, Time);
        }
        else
            left = mid + 1;
    }
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        sum += (Time - 1) / v[i];//n명을 전부 태울수있는 시간-1초에 몇명까지 탈수있는지
    }
    for (int i = 0; i < m; i++) {
        if (Time % v[i] == 0)//마지막 n명을 태울수있는 놈을 찾기
            sum++;
        if (sum == n) {
            cout << i + 1 << "\n";
            return;
        }
    }
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
 
 
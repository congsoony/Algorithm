#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// 구간 [L, R]들(정수, 서로 겹치지 않음) 위에
// 최소 간격 d로 정수 점을 배치할 때
// 최대 몇 개까지 놓을 수 있는지를 그리디로 계산
long long countPlaceable(const vector<pair<long long,long long>>& segs, long long d) {
    long long placed = 0;
    // last는 마지막으로 놓은 점의 좌표
    // 아직 아무 점도 안 놓았음을 표시하기 위해 아주 작은 값 사용
    long long last = LLONG_MIN / 4;

    for (auto [L, R] : segs) {
        // 이 구간에서 처음으로 놓을 수 있는 좌표
        long long first = max(L, (last == LLONG_MIN / 4 ? L : last + d));
        if (first > R) continue;

        // 이 구간에서 d 간격으로 몇 개 더 놓을 수 있는지
        // first, first + d, first + 2d, ... <= R
        long long k = (R - first) / d + 1;  // 놓을 수 있는 개수
        placed += k;
        last = first + (k - 1) * d;        // 이 구간에서 마지막으로 놓은 좌표
    }
    return placed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<pair<long long,long long>> segs(m);
    for (int i = 0; i < m; ++i) {
        long long L, R; cin >> L >> R;
        if (L > R) swap(L, R);
        segs[i] = {L, R};
    }

    // 구간을 좌표 기준 정렬(문제에서 겹치지 않는다고 했지만 정렬은 안전하게)
    sort(segs.begin(), segs.end());

    // 총 정수 격자 수가 n보다 적으면 불가능(-1 등 처리)
    long long total = 0;
    for (auto [L, R] : segs) {
        // 오버플로 방지
        if (total > (long long)4e18) break;
        total += (R - L + 1);
    }
    if (total < n) {
        cout << -1 << "\n";
        return 0;
    }

    // 이분 탐색 범위 설정: 최소 0, 최대는 전체 좌표폭
    long long globalL = segs.front().first;
    long long globalR = segs.back().second;
    long long lo = 0, hi = max(0LL, globalR - globalL), ans = 0;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2; // 시도할 최소 간격 d
        if (countPlaceable(segs, mid) >= n) {
            ans = mid;          // 가능 → 더 큰 간격 시도
            lo = mid + 1;
        } else {
            hi = mid - 1;       // 불가능 → 더 작은 간격
        }
    }

    cout << ans << "\n";
    return 0;
}
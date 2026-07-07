#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

string N;
int L;

// memo[pos][rem]
// tight == false일 때만 저장
// pos번째 자리까지 진행했고, 현재 자리수 합 % 3 == rem일 때
// 만들 수 있는 "박수 안 치는 숫자"의 개수
long long memo[100005][3];

bool allowedDigit(int d) {
    return d != 3 && d != 6 && d != 9;
}

long long dfs(int pos, int rem, bool tight) {
    // 모든 자리를 다 정한 경우
    if (pos == L) {
        // rem != 0이면 3의 배수가 아님
        // 즉 박수를 안 치는 숫자
        return rem != 0 ? 1 : 0;
    }

    // tight가 false면 이미 N보다 작은 숫자임
    // 이 상태는 다시 나올 수 있으므로 메모이제이션 가능
    if (!tight && memo[pos][rem] != -1) {
        return memo[pos][rem];
    }

    int limit = tight ? N[pos] - '0' : 9;

    long long result = 0;

    for (int d = 0; d <= limit; d++) {
        // 숫자에 3, 6, 9가 들어가면 박수 대상이므로 제외
        if (!allowedDigit(d)) continue;

        bool nextTight = tight && (d == limit);
        int nextRem = (rem + d) % 3;

        result += dfs(pos + 1, nextRem, nextTight);
        result %= MOD;
    }

    if (!tight) {
        memo[pos][rem] = result;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    L = N.size();

    memset(memo, -1, sizeof(memo));

    // N은 너무 크므로 MOD 값만 계산
    long long nMod = 0;
    for (char c : N) {
        nMod = (nMod * 10 + (c - '0')) % MOD;
    }

    // 박수를 안 치는 숫자 개수
    long long noClap = dfs(0, 0, true);

    // 전체 숫자는 1부터 N까지 총 N개
    // 답 = 전체 개수 - 박수 안 치는 숫자 개수
    long long answer = (nMod - noClap + MOD) % MOD;

    cout << answer << '\n';

    return 0;
}
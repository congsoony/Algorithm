#include <iostream>
#include <string>
#include <vector>
#include <cstring> // memset 사용을 위해 포함

using namespace std;

const int MOD = 1e9 + 7;

// memo[자릿수][is_less][has_369][mod3]
// 아직 계산되지 않은 상태를 구분하기 위해 초기값을 -1로 세팅합니다.
int memo[100005][2][2][3];
string N;

// 탑다운 재귀 함수
int solve(int idx, int is_less, int has_369, int mod3) {
    // 기저 사례(Base case): 마지막 자리까지 모두 탐색한 경우
    if (idx == N.length()) {
        // 3, 6, 9가 포함되어 있거나 3의 배수라면 1(성공), 아니면 0 반환
        if (has_369 == 1 || mod3 == 0) return 1;
        return 0;
    }

    // 메모이제이션: 이미 계산한 적이 있는 상태라면 그 값을 바로 반환
    if (memo[idx][is_less][has_369][mod3] != -1) {
        return memo[idx][is_less][has_369][mod3];
    }

    // 현재 자리에 들어갈 수 있는 숫자의 최댓값 설정
    int limit = is_less ? 9 : (N[idx] - '0');
    long long ret = 0;

    // 0부터 limit까지 숫자를 하나씩 넣어보며 다음 상태로 재귀 호출
    for (int digit = 0; digit <= limit; digit++) {
        int next_is_less = is_less || (digit < (N[idx] - '0'));
        int next_has_369 = has_369 || (digit == 3 || digit == 6 || digit == 9);
        int next_mod3 = (mod3 * 10 + digit) % 3;

        ret = (ret + solve(idx + 1, next_is_less, next_has_369, next_mod3)) % MOD;
    }

    // 계산 결과를 메모 테이블에 저장 후 반환 (중복 계산 방지)
    return memo[idx][is_less][has_369][mod3] = ret;
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    // 메모 테이블을 -1로 초기화
    memset(memo, -1, sizeof(memo));

    // 0번째 자리부터 재귀 탐색 시작
    long long ans = solve(0, 0, 0, 0);

    // 예외 처리: 모든 자리가 0인 '000...0'은 게임 범위(1~N)에 포함되지 않으므로 1을 뺌
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << "\n";

    return 0;
}
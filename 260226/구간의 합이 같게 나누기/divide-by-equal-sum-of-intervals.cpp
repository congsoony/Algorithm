#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    long long total_sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    // 전체 합이 4로 나누어 떨어지지 않으면 불가능
    if (total_sum % 4 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long target = total_sum / 4;
    
    // cnt1: 1번째 분할선(누적합 = target)을 찾은 횟수
    // cnt2: 2번째 분할선(누적합 = 2 * target)까지 가능한 조합의 수
    // ans: 3번째 분할선(누적합 = 3 * target)까지 가능한 최종 정답 수
    long long cnt1 = 0, cnt2 = 0, ans = 0;
    long long current_sum = 0;

    // 4번째 구간은 최소 1개의 원소를 가져야 하므로 n-1까지만 순회 (마지막 원소 앞까지만 분할 가능)
    for (int i = 0; i < n - 1; i++) {
        current_sum += a[i];
        
        // ⚠️ [매우 중요] 조건 검사 순서: 3 -> 2 -> 1
        // target이 0인 경우(모든 구간 합이 0), 한 인덱스에서 동시에 여러 분할선으로 
        // 중복 계산되는 것을 막기 위해 반드시 역순으로 더해줘야 합니다.
        if (current_sum == 3 * target) {
            ans += cnt2;
        }
        if (current_sum == 2 * target) {
            cnt2 += cnt1;
        }
        if (current_sum == target) {
            cnt1++;
        }
    }

    cout << ans << "\n";

    return 0;
}
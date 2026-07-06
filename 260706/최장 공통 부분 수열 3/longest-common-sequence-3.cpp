#include <bits/stdc++.h>
using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> s1(n + 1), s2(m + 1);
    for(int i = 1; i <= n; i++) cin >> s1[i];

    // B 수열의 각 원소가 등장하는 인덱스를 저장 (원소 값 최대 1000)
    vector<int> posB(1005, 0);
    for(int i = 1; i <= m; i++) {
        cin >> s2[i];
        posB[s2[i]] = i;
    }

    // dp[i][j] : A[i..N]과 B[j..M]의 LCS 길이 (뒤에서부터 계산)
    // 인덱스 초과를 막기 위해 n+2, m+2 크기로 할당
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    int L = dp[1][1]; // 찾아야 하는 전체 LCS 길이
    vector<int> res;
    int i = 1, j = 1;

    // 앞에서부터 사전순으로 가장 작은 원소 찾기
    while(L > 0) {
        int best_val = 1e9;
        int next_i = -1, next_j = -1;

        // 현재 위치(i)부터 남은 A 수열을 순회하며 후보를 찾음
        for(int x = i; x <= n; x++) {
            int y = posB[s1[x]];
            
            // 1. B 배열에 해당 원소가 존재하고 (y > 0)
            // 2. 현재 탐색 가능한 범위 내에 있으며 (y >= j)
            // 3. 해당 원소를 선택했을 때 남은 LCS 길이 L을 충족할 수 있는지 확인
            if(y >= j && dp[x][y] == L) {
                if(s1[x] < best_val) {
                    best_val = s1[x];
                    next_i = x;
                    next_j = y;
                }
            }
        }

        res.push_back(best_val);
        
        // 선택한 원소의 다음 인덱스부터 탐색 재개
        i = next_i + 1;
        j = next_j + 1;
        L--;
    }

    // 결과 출력
    for(int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
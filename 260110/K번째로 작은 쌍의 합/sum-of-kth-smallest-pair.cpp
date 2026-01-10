#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;
    int i, j; // A[i] + B[j]
    bool operator>(const Node& other) const {
        return sum > other.sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int K;
    cin >> N >> M >> K;

    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 힙 크기를 줄이기 위해 더 짧은 배열을 A로 두는 게 유리
    if (A.size() > B.size()) {
        swap(A, B);
        swap(N, M);
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    int init = min(N, K); // K개까지만 초기 투입해도 K번째를 구하는 데 충분
    for (int i = 0; i < init; i++) {
        pq.push({A[i] + B[0], i, 0});
    }

    long long ans = 0;
    for (int t = 0; t < K; t++) {
        auto cur = pq.top(); pq.pop();
        ans = cur.sum;

        int i = cur.i, j = cur.j;
        if (j + 1 < M) {
            pq.push({A[i] + B[j + 1], i, j + 1});
        }
    }

    cout << ans << "\n";
    return 0;
}
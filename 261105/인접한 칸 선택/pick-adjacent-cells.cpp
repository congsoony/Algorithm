#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<vector<int>>> dp;

int dfs(int y = 0, int x = 0, int bit = 0) {
    if (x >= m) return dfs(y + 1, 0, bit);
    if (y >= n) return 0;
    
    int &cache = dp[y][x][bit];
    if (cache != -1e8) return cache;
    
    // --- [선택하지 않는 경우] ---
    // 시프트(<<) 없이, 현재 열(x)의 비트만 0으로 확실하게 꺼줍니다 ( & ~(1<<x) )
    // 왜냐하면 이전 행에서 1이었을 수도 있으니까 현재는 안 골랐다는 뜻으로 0을 덮어씌우는 겁니다.
    int next_bit_not_pick = bit & ~(1 << x);
    cache = dfs(y, x + 1, next_bit_not_pick);
    
    // --- [선택하는 경우] ---
    if (v[y][x] == 0) { 
        bool can_pick = true;
        
        // 1. 윗 칸 검사: 현재 열(x)의 비트가 켜져 있는지 확인
        if (y > 0 && (bit & (1 << x))) can_pick = false;
        
        // 2. 왼쪽 칸 검사: 이전 열(x-1)의 비트가 켜져 있는지 확인
        if (x > 0 && (bit & (1 << (x - 1)))) can_pick = false;
        
        if (can_pick) {
            // 선택했으므로, 현재 열(x)의 비트에 1을 켜줍니다 ( | (1<<x) )
            int next_bit_pick = bit | (1 << x);
            cache = max(cache, dfs(y, x + 1, next_bit_pick) + 1);
        }
    }
    
    return cache;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    v = vector<vector<int>>(n, vector<int>(m));
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1 << m, -1e8)));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    
    cout << dfs() << "\n";
    return 0;
}
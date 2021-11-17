#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = 0, m = matrix[0].size();
        int left = 0, right = m - 1;
        int idx = -1;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][left] <= target && target <= matrix[i][right])
                idx = i;
        }
        if (idx == -1)return false;
        int t = lower_bound(matrix[idx].begin(), matrix[idx].end(), target)-matrix[idx].begin();
        if (t >= m)return false;
        return matrix[idx][t] == target;
    }
};
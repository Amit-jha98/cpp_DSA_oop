// 69. Longest Increasing Path in a Matrix
// Find the length of the longest strictly increasing path in the matrix,
// moving up/down/left/right.
// Theory / Approach:
// Use DFS with memoization from each cell. The answer for a cell is 1 plus the
// best answer among neighboring cells with larger values.
//
// Why this works:
// Increasing moves form a directed acyclic graph by value. Memoization computes
// each cell's longest path once.
//
// Time Complexity: O(mn)
// Space Complexity: O(mn)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int best = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                best = max(best, dfs(matrix, memo, i, j));
        return best;
    }
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != 0) return memo[i][j];
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int best = 1;
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < (int)matrix.size() && nj >= 0 && nj < (int)matrix[0].size()
                && matrix[ni][nj] > matrix[i][j]) {
                best = max(best, 1 + dfs(matrix, memo, ni, nj));
            }
        }
        memo[i][j] = best;
        return best;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << "Longest Increasing Path: " << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}

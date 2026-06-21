// 28. Unique Paths
// Count unique paths from top-left to bottom-right of an m x n grid,
// moving only right or down.
// Theory / Approach:
// A robot can enter each cell only from the top or left. Use DP to accumulate
// ways for each cell from those two neighbors.
//
// Why this works:
// The allowed moves create independent subproblems. Every path to a cell ends
// with exactly one of the two possible previous cells.
//
// Time Complexity: O(mn)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    cout << "m=3, n=7 -> " << sol.uniquePaths(3, 7) << endl;
    cout << "m=3, n=2 -> " << sol.uniquePaths(3, 2) << endl;
    return 0;
}

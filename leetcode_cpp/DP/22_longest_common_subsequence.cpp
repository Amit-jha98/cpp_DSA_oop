// 22. Longest Common Subsequence
// Length of the longest subsequence common to two strings.
// Theory / Approach:
// Use 2D DP where dp[i][j] is the LCS length for the first i characters of text1
// and first j characters of text2. Match characters extend the answer; otherwise take the best skip.
//
// Why this works:
// The last characters either match and belong to the LCS, or at least one of
// them must be excluded. DP explores both possibilities without recomputation.
//
// Time Complexity: O(mn)
// Space Complexity: O(mn)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    cout << "text1=\"abcde\", text2=\"ace\" -> " << sol.longestCommonSubsequence("abcde", "ace") << endl;
    cout << "text1=\"abc\", text2=\"abc\" -> " << sol.longestCommonSubsequence("abc", "abc") << endl;
    cout << "text1=\"abc\", text2=\"def\" -> " << sol.longestCommonSubsequence("abc", "def") << endl;
    return 0;
}

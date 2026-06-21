// 33. Regular Expression Matching
// Implement regex matching supporting '.' and '*'.
// Theory / Approach:
// Use DP where dp[i][j] means s[0..i) matches p[0..j). Normal characters and '.'
// match one character; '*' can mean zero of the previous token or one more match.
//
// Why this works:
// Matching depends only on smaller prefixes of the string and pattern. The '*'
// transition captures both skip and repeat behavior.
//
// Time Complexity: O(mn)
// Space Complexity: O(mn)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1)); // -1 unknown, 0 false, 1 true
        return dp(s, p, 0, 0, memo);
    }
private:
    bool dp(const string& s, const string& p, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j];
        bool res;
        if (j == (int)p.size()) {
            res = (i == (int)s.size());
        } else {
            bool firstMatch = (i < (int)s.size()) && (p[j] == s[i] || p[j] == '.');
            if (j + 1 < (int)p.size() && p[j+1] == '*') {
                // zero occurrences of p[j], or one+ if firstMatch
                res = dp(s, p, i, j + 2, memo) || (firstMatch && dp(s, p, i + 1, j, memo));
            } else {
                res = firstMatch && dp(s, p, i + 1, j + 1, memo);
            }
        }
        memo[i][j] = res ? 1 : 0;
        return res;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "s=\"aa\", p=\"a\" -> " << sol.isMatch("aa", "a") << endl;
    cout << "s=\"aa\", p=\"a*\" -> " << sol.isMatch("aa", "a*") << endl;
    cout << "s=\"ab\", p=\".*\" -> " << sol.isMatch("ab", ".*") << endl;
    cout << "s=\"mississippi\", p=\"mis*is*p*.\" -> " << sol.isMatch("mississippi", "mis*is*p*.") << endl;
    return 0;
}

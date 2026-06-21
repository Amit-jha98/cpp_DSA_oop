// 27. Decode Ways
// Count the number of ways to decode a digit string where
// 'A'->1 ... 'Z'->26.
// Theory / Approach:
// Use DP over the string. A position can be decoded from one valid digit or from
// a valid two-digit number between 10 and 26.
//
// Why this works:
// Every decoding ending at i uses either the last one digit or last two digits
// as its final letter. Summing those valid choices counts all decodings.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int oneDigit = s[i-1] - '0';
            int twoDigit = (s[i-2] - '0') * 10 + oneDigit;
            if (oneDigit >= 1) dp[i] += dp[i-1];
            if (twoDigit >= 10 && twoDigit <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    cout << "s=\"12\" -> " << sol.numDecodings("12") << endl;
    cout << "s=\"226\" -> " << sol.numDecodings("226") << endl;
    cout << "s=\"06\" -> " << sol.numDecodings("06") << endl;
    return 0;
}

// 23. Word Break Problem
// Determine if s can be segmented into a space-separated sequence of
// one or more dictionary words.
// Theory / Approach:
// Use DP where dp[i] means s[0..i) can be segmented into dictionary words.
// For each reachable prefix, test whether a dictionary word can end at i.
//
// Why this works:
// A valid segmentation ending at i is a valid earlier prefix plus one dictionary
// word. Checking all split points covers every possible final word.
//
// Time Complexity: O(n^2) average with substring checks
// Space Complexity: O(n + dictionary size)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    vector<string> dict = {"leet", "code"};
    cout << boolalpha;
    cout << "s=\"leetcode\", dict=[leet,code] -> " << sol.wordBreak("leetcode", dict) << endl;
    vector<string> dict2 = {"apple", "pen"};
    cout << "s=\"applepenapple\", dict=[apple,pen] -> " << sol.wordBreak("applepenapple", dict2) << endl;
    return 0;
}

// 86. Longest Common Prefix
// Find the longest common prefix string amongst an array of strings.
// Theory / Approach:
// Start with the first string as the prefix and shrink it until every string
// begins with that prefix.
//
// Why this works:
// The common prefix cannot be longer than any individual string. Removing
// trailing characters preserves all possible candidates until one fits all strings.
//
// Time Complexity: O(total characters)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < (int)strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower","flow","flight"};
    cout << "Input: [flower,flow,flight] -> \"" << sol.longestCommonPrefix(strs) << "\"\n";
    vector<string> strs2 = {"dog","racecar","car"};
    cout << "Input: [dog,racecar,car] -> \"" << sol.longestCommonPrefix(strs2) << "\"\n";
    return 0;
}

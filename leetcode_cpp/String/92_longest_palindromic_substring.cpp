// 92. Longest Palindromic Substring
// Find the longest palindromic substring, using expand-around-center.
// Theory / Approach:
// Expand around every possible center, considering both odd and even length
// palindromes. Track the longest valid expansion.
//
// Why this works:
// Every palindrome has a center. Expanding from each center discovers the
// longest palindrome with that center.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int bestStart = 0, bestLen = 1;
        for (int i = 0; i < (int)s.size(); ++i) {
            int len1 = expand(s, i, i);     // odd length
            int len2 = expand(s, i, i + 1); // even length
            int len = max(len1, len2);
            if (len > bestLen) {
                bestLen = len;
                bestStart = i - (len - 1) / 2;
            }
        }
        return s.substr(bestStart, bestLen);
    }
private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            --left; ++right;
        }
        return right - left - 1;
    }
};

int main() {
    Solution sol;
    cout << "s=\"babad\" -> " << sol.longestPalindrome("babad") << endl;
    cout << "s=\"cbbd\" -> " << sol.longestPalindrome("cbbd") << endl;
    return 0;
}

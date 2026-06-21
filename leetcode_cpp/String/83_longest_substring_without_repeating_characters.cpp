// 83. Longest Substring Without Repeating Characters
// Find the length of the longest substring without repeating characters.
// Theory / Approach:
// Use a sliding window with last seen positions. When a duplicate appears inside
// the current window, move the left boundary past its previous occurrence.
//
// Why this works:
// The window always contains unique characters. Expanding right and adjusting
// left explores every maximal valid substring.
//
// Time Complexity: O(n)
// Space Complexity: O(1) for fixed character set.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastSeen;
        int best = 0, left = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            if (lastSeen.count(c) && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            lastSeen[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};

int main() {
    Solution sol;
    cout << "s=\"abcabcbb\" -> " << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "s=\"bbbbb\" -> " << sol.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "s=\"pwwkew\" -> " << sol.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}

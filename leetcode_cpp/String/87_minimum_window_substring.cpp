// 87. Minimum Window Substring
// Find the minimum window in s which contains all characters of t.
// Theory / Approach:
// Use a sliding window with character counts. Expand right until all required
// characters are included, then shrink left while the window remains valid.
//
// Why this works:
// Every valid window is considered when its right edge is reached, and shrinking
// finds the smallest valid window for that right edge.
//
// Time Complexity: O(n)
// Space Complexity: O(1) for fixed character set.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char,int> need;
        for (char c : t) need[c]++;
        int required = need.size();
        unordered_map<char,int> window;
        int formed = 0;
        int left = 0, bestLen = INT_MAX, bestStart = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) ++formed;

            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                char lc = s[left];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc]) --formed;
                ++left;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};

int main() {
    Solution sol;
    cout << "s=\"ADOBECODEBANC\", t=\"ABC\" -> \"" << sol.minWindow("ADOBECODEBANC", "ABC") << "\"\n";
    return 0;
}

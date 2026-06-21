// 84. Longest Repeating Character Replacement
// Find the length of the longest substring containing the same letter
// after replacing at most k characters.
// Theory / Approach:
// Use a sliding window and track the most frequent character count in the
// window. The window is valid if window length - max frequency <= k.
//
// Why this works:
// To make all characters equal, replace every character except the most frequent
// one. Shrinking only when replacements exceed k keeps the best window.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0, maxCount = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            maxCount = max(maxCount, ++count[s[right]-'A']);
            while ((right - left + 1) - maxCount > k) {
                --count[s[left]-'A'];
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};

int main() {
    Solution sol;
    cout << "s=\"ABAB\", k=2 -> " << sol.characterReplacement("ABAB", 2) << endl;
    cout << "s=\"AABABBA\", k=1 -> " << sol.characterReplacement("AABABBA", 1) << endl;
    return 0;
}

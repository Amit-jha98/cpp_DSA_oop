// 94. Palindromic Substrings
// Count how many palindromic substrings exist in s.
// Theory / Approach:
// Expand around every center and count each successful palindrome expansion.
// Include both single-character centers and gaps between characters.
//
// Why this works:
// Every palindromic substring has a unique center, so center expansion counts
// all palindromes without duplicates.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            count += expand(s, i, i);     // odd length
            count += expand(s, i, i + 1); // even length
        }
        return count;
    }
private:
    int expand(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            ++count;
            --left; ++right;
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << "s=\"abc\" -> " << sol.countSubstrings("abc") << endl;
    cout << "s=\"aaa\" -> " << sol.countSubstrings("aaa") << endl;
    return 0;
}

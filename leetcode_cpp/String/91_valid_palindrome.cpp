// 91. Valid Palindrome
// Determine if a string is a palindrome, considering only alphanumeric
// characters and ignoring case.
// Theory / Approach:
// Use two pointers from both ends, skipping non-alphanumeric characters and
// comparing lowercase forms.
//
// Why this works:
// A palindrome reads the same from both directions after ignoring punctuation
// and case, so paired characters must match.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) ++left;
            while (left < right && !isalnum(s[right])) --right;
            if (tolower(s[left]) != tolower(s[right])) return false;
            ++left; --right;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "s=\"A man, a plan, a canal: Panama\" -> "
         << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << "s=\"race a car\" -> " << sol.isPalindrome("race a car") << endl;
    return 0;
}

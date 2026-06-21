// 88. Valid Anagram
// Determine if t is an anagram of s.
// Theory / Approach:
// Count character frequencies in one string and subtract frequencies from the
// other. The strings are anagrams only if all counts end at zero.
//
// Why this works:
// Anagrams contain exactly the same characters with exactly the same counts,
// regardless of order.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int count[26] = {0};
        for (char c : s) count[c-'a']++;
        for (char c : t) count[c-'a']--;
        for (int x : count) if (x != 0) return false;
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "s=\"anagram\", t=\"nagaram\" -> " << sol.isAnagram("anagram", "nagaram") << endl;
    cout << "s=\"rat\", t=\"car\" -> " << sol.isAnagram("rat", "car") << endl;
    return 0;
}

// 100. Minimum Remove to Make Valid Parentheses
// Remove the minimum number of parentheses so the string is valid,
// keeping all other characters.
// Theory / Approach:
// Use a stack to remember unmatched '(' indices and mark invalid ')' as removed.
// After scanning, remove any unmatched '(' left in the stack.
//
// Why this works:
// A valid ')' must match the most recent unmatched '('. Anything that cannot be
// matched must be deleted.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> toRemove;
        stack<int> st;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (!st.empty()) st.pop();
                else toRemove.push_back(i);
            }
        }
        while (!st.empty()) { toRemove.push_back(st.top()); st.pop(); }
        sort(toRemove.begin(), toRemove.end());

        string res;
        int idx = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (idx < (int)toRemove.size() && toRemove[idx] == i) { ++idx; continue; }
            res += s[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << "s=\"lee(t(c)o)de)\" -> \"" << sol.minRemoveToMakeValid("lee(t(c)o)de)") << "\"\n";
    cout << "s=\"a)b(c)d\" -> \"" << sol.minRemoveToMakeValid("a)b(c)d") << "\"\n";
    cout << "s=\"))((\" -> \"" << sol.minRemoveToMakeValid("))((") << "\"\n";
    return 0;
}

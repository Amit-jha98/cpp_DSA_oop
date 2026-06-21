// 101. Longest Valid Parentheses
// Find the length of the longest valid (well-formed) parentheses substring.
// Theory / Approach:
// Use a stack of indices, initialized with -1 as a base. Push '(' indices; for
// ')' pop once, then use the new top as the boundary for a valid length.
//
// Why this works:
// The stack stores unmatched opening positions and the last invalid boundary.
// The distance from the current index to that boundary is the current valid length.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // sentinel base index
        int best = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // new base
                } else {
                    best = max(best, i - st.top());
                }
            }
        }
        return best;
    }
};

int main() {
    Solution sol;
    cout << "s=\"(()\" -> " << sol.longestValidParentheses("(()") << endl;
    cout << "s=\")()())\" -> " << sol.longestValidParentheses(")()())") << endl;
    cout << "s=\"\" -> " << sol.longestValidParentheses("") << endl;
    return 0;
}

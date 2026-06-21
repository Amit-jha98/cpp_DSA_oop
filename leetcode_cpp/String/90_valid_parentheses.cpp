// 90. Valid Parentheses
// Determine if the input string of brackets is valid (properly closed
// and nested).
// Theory / Approach:
// Use a stack of opening brackets. For each closing bracket, the stack top must
// be the matching opening bracket.
//
// Why this works:
// Parentheses must close in reverse order of opening, which is exactly the
// behavior of a stack.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> pairs = {{')','('},{']','['},{'}','{'}};
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << "s=\"()[]{}\" -> " << sol.isValid("()[]{}") << endl;
    cout << "s=\"(]\" -> " << sol.isValid("(]") << endl;
    cout << "s=\"([)]\" -> " << sol.isValid("([)]") << endl;
    return 0;
}

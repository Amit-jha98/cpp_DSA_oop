// 30. Generate Parentheses
// Generate all combinations of well-formed parentheses for n pairs.
// Theory / Approach:
// Backtrack while tracking how many opening and closing parentheses have been
// used. Add '(' if openings remain; add ')' only if it will not exceed openings.
//
// Why this works:
// The close count never exceeding the open count is exactly the rule that keeps
// every prefix valid. Exploring all valid choices creates every valid string.
//
// Time Complexity: O(Catalan(n) * n)
// Space Complexity: O(n) recursion depth, excluding the answer.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(res, cur, 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string>& res, string& cur, int open, int close, int n) {
        if ((int)cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(res, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(res, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
};

int main() {
    Solution sol;
    auto res = sol.generateParenthesis(3);
    cout << "n=3\nResult:\n";
    for (auto& s : res) cout << s << endl;
    return 0;
}

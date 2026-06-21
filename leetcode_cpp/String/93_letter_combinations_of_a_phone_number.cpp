// 93. Letter Combinations of a Phone Number
// Return all possible letter combinations the number could represent,
// based on a telephone keypad.
// Theory / Approach:
// Use backtracking. For each digit, append each possible mapped letter and
// recurse to the next digit.
//
// Why this works:
// Each output string chooses one letter per digit. The recursion tree enumerates
// every combination exactly once.
//
// Time Complexity: O(4^n * n)
// Space Complexity: O(n) recursion depth, excluding the answer.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char,string> mapping = {
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
            {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        vector<string> res;
        string cur;
        backtrack(digits, 0, cur, mapping, res);
        return res;
    }
private:
    void backtrack(const string& digits, int idx, string& cur,
                    unordered_map<char,string>& mapping, vector<string>& res) {
        if (idx == (int)digits.size()) {
            res.push_back(cur);
            return;
        }
        for (char c : mapping[digits[idx]]) {
            cur.push_back(c);
            backtrack(digits, idx + 1, cur, mapping, res);
            cur.pop_back();
        }
    }
};

int main() {
    Solution sol;
    auto res = sol.letterCombinations("23");
    cout << "digits=\"23\"\nCombinations: ";
    for (auto& s : res) cout << s << " ";
    cout << endl;
    return 0;
}

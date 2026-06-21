// 24. Combination Sum
// Find all unique combinations of candidates that sum to target.
// Same number may be chosen unlimited times.
// Theory / Approach:
// Use backtracking. At each step, choose a candidate starting from the current
// index so combinations stay nondecreasing and the same number can be reused.
//
// Why this works:
// The remaining target shrinks after each choice. Keeping the start index
// prevents generating the same combination in different orders.
//
// Time Complexity: Exponential in the number of valid combinations
// Space Complexity: O(target depth), excluding the answer.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, path, res);
        return res;
    }
private:
    void backtrack(vector<int>& cand, int remain, int start, vector<int>& path, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)cand.size(); ++i) {
            if (cand[i] > remain) break;
            path.push_back(cand[i]);
            backtrack(cand, remain - cand[i], i, path, res); // i, not i+1: reuse allowed
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    auto res = sol.combinationSum(candidates, 7);
    cout << "candidates=[2,3,6,7], target=7\nCombinations:\n";
    for (auto& c : res) {
        cout << "[";
        for (int i = 0; i < (int)c.size(); ++i) cout << c[i] << (i+1<(int)c.size()?",":"");
        cout << "]\n";
    }
    return 0;
}

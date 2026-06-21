// 51. Merge Intervals
// Merge all overlapping intervals.
// Theory / Approach:
// Sort intervals by start time, then scan and merge the current interval into
// the previous result if they overlap.
//
// Why this works:
// After sorting, any interval that can overlap the current merged interval must
// appear next in order. Non-overlapping intervals can be safely finalized.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n) for the result.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    auto res = sol.merge(intervals);
    cout << "Input: [[1,3],[2,6],[8,10],[15,18]]\nOutput: ";
    for (auto& iv : res) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;
    return 0;
}

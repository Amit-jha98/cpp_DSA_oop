// 50. Insert Interval
// Insert a new interval into a sorted, non-overlapping list of intervals,
// merging as necessary.
// Theory / Approach:
// Add intervals before the new interval, merge every interval that overlaps it,
// then append the remaining intervals.
//
// Why this works:
// The input is sorted by start time, so overlaps with the new interval form one
// continuous block.
//
// Time Complexity: O(n)
// Space Complexity: O(n) for the result.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            ++i;
        }
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    auto res = sol.insert(intervals, newInterval);
    cout << "Input: [[1,3],[6,9]], newInterval=[2,5]\nOutput: ";
    for (auto& iv : res) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;
    return 0;
}

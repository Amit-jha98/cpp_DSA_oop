// 52. Non-overlapping Intervals
// Find the minimum number of intervals to remove so the rest are
// non-overlapping.
// Theory / Approach:
// Sort intervals by end time and greedily keep intervals that start after the
// last kept end. Count the intervals that must be removed.
//
// Why this works:
// Keeping the interval with the earliest end leaves maximum room for future
// intervals, which minimizes removals.
//
// Time Complexity: O(n log n)
// Space Complexity: O(1) extra space after sorting.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) {
                ++count; // remove this interval
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Input: [[1,2],[2,3],[3,4],[1,3]]\n";
    cout << "Removals needed: " << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}

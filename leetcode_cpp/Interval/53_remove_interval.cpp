// 53. Remove Interval
// Remove toBeRemoved from a sorted list of disjoint intervals, returning
// the remaining set of intervals.
// Theory / Approach:
// For each interval, keep the parts that lie completely outside the interval to
// remove. An overlap may produce a left remainder, a right remainder, or both.
//
// Why this works:
// Removing a fixed range from each interval is independent. Splitting around the
// removed range preserves exactly the remaining covered portions.
//
// Time Complexity: O(n)
// Space Complexity: O(n) for the result.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        int rs = toBeRemoved[0], re = toBeRemoved[1];
        for (auto& iv : intervals) {
            int s = iv[0], e = iv[1];
            if (e <= rs || s >= re) {
                // no overlap
                res.push_back({s, e});
            } else {
                if (s < rs) res.push_back({s, rs});
                if (e > re) res.push_back({re, e});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{0,2},{3,4},{5,7}};
    vector<int> toBeRemoved = {1,6};
    auto res = sol.removeInterval(intervals, toBeRemoved);
    cout << "Input: [[0,2],[3,4],[5,7]], toBeRemoved=[1,6]\nOutput: ";
    for (auto& iv : res) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;
    return 0;
}

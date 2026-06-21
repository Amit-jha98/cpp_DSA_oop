// 125. Employee Free Time
// Given a list of schedules (each a list of non-overlapping intervals,
// sorted), find the common free time intervals shared by all employees.
// Theory / Approach:
// Flatten all employee intervals, sort by start time, and merge busy intervals.
// Gaps between merged busy intervals are common free time.
//
// Why this works:
// Someone is busy during the union of all busy intervals. Common free time is
// exactly the complement gaps between those merged intervals.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> all;
        for (auto& emp : schedule) for (auto& iv : emp) all.push_back(iv);
        sort(all.begin(), all.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        vector<Interval> res;
        int end = all[0].end;
        for (int i = 1; i < (int)all.size(); ++i) {
            if (all[i].start > end) {
                res.push_back(Interval(end, all[i].start));
                end = all[i].end;
            } else {
                end = max(end, all[i].end);
            }
        }
        return res;
    }
};

int main() {
    // Employee 1: [1,2],[5,6]
    // Employee 2: [1,3]
    // Employee 3: [4,10]
    vector<vector<Interval>> schedule = {
        { Interval(1,2), Interval(5,6) },
        { Interval(1,3) },
        { Interval(4,10) }
    };
    Solution sol;
    auto res = sol.employeeFreeTime(schedule);
    cout << "Free time intervals: ";
    for (auto& iv : res) cout << "[" << iv.start << "," << iv.end << "] ";
    cout << endl;
    return 0;
}

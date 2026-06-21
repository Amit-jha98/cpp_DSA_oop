// 54. Meeting Rooms (LeetCode Premium)
// Given a list of meeting time intervals, determine if a person could
// attend all meetings (i.e., no overlaps).
// Theory / Approach:
// Sort meetings by start time and check whether any meeting starts before the
// previous meeting ends.
//
// Why this works:
// After sorting, the only possible conflict for a meeting is with the meeting
// immediately before it.
//
// Time Complexity: O(n log n)
// Space Complexity: O(1) extra space after sorting.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    cout << "Input: [[0,30],[5,10],[15,20]] -> " << sol.canAttendMeetings(intervals) << endl;
    vector<vector<int>> intervals2 = {{7,10},{2,4}};
    cout << "Input: [[7,10],[2,4]] -> " << sol.canAttendMeetings(intervals2) << endl;
    return 0;
}

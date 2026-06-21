// 55. Meeting Rooms II (LeetCode Premium)
// Find the minimum number of conference rooms required.
// Theory / Approach:
// Sort start times and end times separately. Sweep through starts, reusing a
// room whenever the earliest ending meeting has finished.
//
// Why this works:
// The number of active meetings at any time is the number of rooms needed. The
// sweep tracks that active count and its maximum.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        vector<int> starts, ends;
        for (auto& iv : intervals) {
            starts.push_back(iv[0]);
            ends.push_back(iv[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;
        int n = starts.size();
        while (i < n) {
            if (starts[i] < ends[j]) {
                ++rooms;
                ++i;
                maxRooms = max(maxRooms, rooms);
            } else {
                --rooms;
                ++j;
            }
        }
        return maxRooms;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    cout << "Input: [[0,30],[5,10],[15,20]]\n";
    cout << "Min Rooms: " << sol.minMeetingRooms(intervals) << endl;
    return 0;
}

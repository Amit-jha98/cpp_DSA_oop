// 32. Jump Game II
// Find the minimum number of jumps to reach the last index.
// Theory / Approach:
// Use a greedy level scan. The current jump covers indices up to curEnd; while
// scanning that range, compute the farthest next range.
//
// Why this works:
// All indices within the current range are reachable with the same number of
// jumps. Once the range ends, taking one more jump to the farthest known reach is optimal.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) {
                ++jumps;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout << "Input: [2,3,1,1,4] -> " << sol.jump(nums) << endl;
    vector<int> nums2 = {2,3,0,1,4};
    cout << "Input: [2,3,0,1,4] -> " << sol.jump(nums2) << endl;
    return 0;
}

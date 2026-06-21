// 31. Jump Game
// Determine if you can reach the last index, where nums[i] is the max jump
// length from index i.
// Theory / Approach:
// Track the farthest index reachable so far. If the scan ever reaches an index
// beyond that range, the end is impossible.
//
// Why this works:
// Each reachable index can extend the reachable boundary. If the current index
// is reachable, all jumps from it are valid candidates.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach) return false;
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    vector<int> nums = {2,3,1,1,4};
    cout << "Input: [2,3,1,1,4] -> " << sol.canJump(nums) << endl;
    vector<int> nums2 = {3,2,1,0,4};
    cout << "Input: [3,2,1,0,4] -> " << sol.canJump(nums2) << endl;
    return 0;
}

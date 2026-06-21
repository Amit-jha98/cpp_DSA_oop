// 25. House Robber
// Maximize money robbed without robbing two adjacent houses.
// Theory / Approach:
// At each house, choose between robbing it plus the best before the previous
// house, or skipping it and keeping the previous best.
//
// Why this works:
// Adjacent houses cannot both be robbed, so those two choices cover all valid
// optimal plans ending at the current position.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int x : nums) {
            int cur = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << "Input: [1,2,3,1] -> " << sol.rob(nums) << endl;
    vector<int> nums2 = {2,7,9,3,1};
    cout << "Input: [2,7,9,3,1] -> " << sol.rob(nums2) << endl;
    return 0;
}

// 26. House Robber II
// Same as House Robber, but houses are arranged in a circle.
// Theory / Approach:
// In a circle, the first and last houses cannot both be robbed. Solve two linear
// House Robber cases: exclude the first house, or exclude the last house.
//
// Why this works:
// Every valid circular solution belongs to one of those two cases. Taking the
// maximum of both linear results gives the best valid plan.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> a(nums.begin(), nums.end() - 1); // exclude last
        vector<int> b(nums.begin() + 1, nums.end());  // exclude first
        return max(robLine(a), robLine(b));
    }
private:
    int robLine(vector<int>& nums) {
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
    vector<int> nums = {2,3,2};
    cout << "Input: [2,3,2] -> " << sol.rob(nums) << endl;
    vector<int> nums2 = {1,2,3,1};
    cout << "Input: [1,2,3,1] -> " << sol.rob(nums2) << endl;
    return 0;
}

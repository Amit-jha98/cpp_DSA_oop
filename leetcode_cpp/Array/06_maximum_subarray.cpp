// 6. Maximum Subarray (Kadane's Algorithm)
// Find the contiguous subarray with the largest sum.
// Theory / Approach:
// Kadane's algorithm keeps the best subarray sum ending at the current index.
// At each number, either extend the previous subarray or start fresh from this
// number if the previous sum hurts us.
//
// Why this works:
// A maximum subarray ending at i only needs one decision: include the best
// subarray ending at i - 1, or begin at i. Tracking the global best gives the answer.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], cur = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Input: [-2,1,-3,4,-1,2,1,-5,4]\n";
    cout << "Max Subarray Sum: " << sol.maxSubArray(nums) << endl;
    return 0;
}

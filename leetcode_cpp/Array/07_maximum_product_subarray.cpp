// 7. Maximum Product Subarray
// Find the contiguous subarray with the largest product.
// Theory / Approach:
// Products are tricky because a negative number can turn the smallest product
// into the largest. Track both the maximum and minimum product ending at each
// index, then update the best answer.
//
// Why this works:
// Every subarray ending at i is either nums[i] alone or nums[i] multiplied by a
// previous max/min product. Keeping both covers sign flips.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxProd = nums[0], minProd = nums[0], best = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            long long val = nums[i];
            long long candMax = max({val, maxProd * val, minProd * val});
            long long candMin = min({val, maxProd * val, minProd * val});
            maxProd = candMax;
            minProd = candMin;
            best = max(best, maxProd);
        }
        return (int)best;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    cout << "Input: [2,3,-2,4]\n";
    cout << "Max Product Subarray: " << sol.maxProduct(nums) << endl;

    vector<int> nums2 = {-2,0,-1};
    cout << "Input: [-2,0,-1]\n";
    cout << "Max Product Subarray: " << sol.maxProduct(nums2) << endl;
    return 0;
}

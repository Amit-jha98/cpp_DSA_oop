// 11. 3Sum
// Find all unique triplets that sum to zero.
// Theory / Approach:
// Sort the array, fix one number, then use the two-pointer Two Sum technique on
// the remaining suffix. Skip repeated values to avoid duplicate triplets.
//
// Why this works:
// Sorting lets us move pointers based on whether the sum is too small or too
// large, and duplicate skipping ensures each value combination is emitted once.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1) extra space, excluding the answer.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                long long sum = (long long)nums[i] + nums[lo] + nums[hi];
                if (sum == 0) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    ++lo; --hi;
                    while (lo < hi && nums[lo] == nums[lo-1]) ++lo;
                    while (lo < hi && nums[hi] == nums[hi+1]) --hi;
                } else if (sum < 0) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = sol.threeSum(nums);
    cout << "Input: [-1,0,1,2,-1,-4]\nTriplets:\n";
    for (auto& t : res) {
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "]\n";
    }
    return 0;
}

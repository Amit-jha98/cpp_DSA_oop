// 21. Longest Increasing Subsequence
// Length of the longest strictly increasing subsequence, O(n log n).
// Theory / Approach:
// Keep tails[len] as the smallest possible ending value of an increasing
// subsequence of length len + 1. Binary search where each number should replace or extend.
//
// Why this works:
// Smaller tails are always better because they leave more room for future
// numbers. The length of tails is the LIS length.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return tails.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Input: [10,9,2,5,3,7,101,18]\n";
    cout << "LIS length: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}

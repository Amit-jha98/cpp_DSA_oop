// 5. Product of Array Except Self
// Return an array where output[i] = product of all elements except nums[i],
// without using division, in O(n) time.
// Theory / Approach:
// The product except self can be split into product of elements on the left and
// product of elements on the right. First store prefix products in the answer,
// then multiply each position by a running suffix product from the right.
//
// Why this works:
// For index i, every element except nums[i] is either before i or after i.
// Combining those two products gives exactly the required value without division.
//
// Time Complexity: O(n)
// Space Complexity: O(1) extra space, excluding the output array.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> res = sol.productExceptSelf(nums);
    cout << "Input: [1,2,3,4]\nOutput: [";
    for (int i = 0; i < (int)res.size(); ++i) cout << res[i] << (i+1<(int)res.size()?",":"");
    cout << "]\n";
    return 0;
}

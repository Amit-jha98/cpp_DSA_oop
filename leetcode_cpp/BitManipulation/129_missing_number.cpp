// 129. Missing Number
// Find the missing number in an array containing n distinct numbers from
// the range [0, n], using XOR.
// Theory / Approach:
// XOR all numbers from 0 to n and all values in the array. Matching values
// cancel out, leaving the missing number.
//
// Why this works:
// XOR of a number with itself is 0, and XOR with 0 is unchanged. Every present
// number appears twice across the two groups.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < (int)nums.size(); ++i) {
            result ^= i ^ nums[i];
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,0,1};
    cout << "Input: [3,0,1] -> " << sol.missingNumber(nums) << endl;
    vector<int> nums2 = {9,6,4,2,3,5,7,0,1};
    cout << "Input: [9,6,4,2,3,5,7,0,1] -> " << sol.missingNumber(nums2) << endl;
    return 0;
}

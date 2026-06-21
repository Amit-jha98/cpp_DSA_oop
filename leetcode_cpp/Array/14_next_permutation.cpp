// 14. Next Permutation
// Rearrange numbers into the lexicographically next greater permutation,
// in place, using O(1) extra memory.
// Theory / Approach:
// Scan from the right to find the first decreasing pivot. Swap it with the
// smallest larger value on its right, then reverse the suffix to make it minimal.
//
// Why this works:
// The suffix after the pivot is in descending order, so the next larger
// permutation changes the pivot as little as possible and resets the suffix to ascending order.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) --i;
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3};
    sol.nextPermutation(nums);
    cout << "Input: [1,2,3]\nNext Permutation: [";
    for (int i = 0; i < (int)nums.size(); ++i) cout << nums[i] << (i+1<(int)nums.size()?",":"");
    cout << "]\n";

    vector<int> nums2 = {3,2,1};
    sol.nextPermutation(nums2);
    cout << "Input: [3,2,1]\nNext Permutation: [";
    for (int i = 0; i < (int)nums2.size(); ++i) cout << nums2[i] << (i+1<(int)nums2.size()?",":"");
    cout << "]\n";
    return 0;
}

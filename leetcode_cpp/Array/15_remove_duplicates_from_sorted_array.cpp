// 15. Remove Duplicates from Sorted Array
// Remove duplicates in place such that each unique element appears once.
// Return the new length.
// Theory / Approach:
// Because duplicates are adjacent in a sorted array, keep a write index k for
// the next unique value. Copy a number only when it differs from the last kept value.
//
// Why this works:
// Every unique value appears first at some position, and that first occurrence is
// copied exactly once into the front of the array.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[k-1]) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,2,3};
    int k = sol.removeDuplicates(nums);
    cout << "Input: [1,1,2,2,3]\nNew length: " << k << "\nArray: [";
    for (int i = 0; i < k; ++i) cout << nums[i] << (i+1<k?",":"");
    cout << "]\n";
    return 0;
}

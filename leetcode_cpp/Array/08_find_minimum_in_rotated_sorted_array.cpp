// 8. Find Minimum in Rotated Sorted Array
// Array of distinct values, originally sorted ascending, then rotated.
// Find the minimum element in O(log n).
// Theory / Approach:
// Use binary search. Compare nums[mid] with nums[hi] to decide which side
// contains the rotation point and therefore the minimum.
//
// Why this works:
// If nums[mid] > nums[hi], the minimum must be to the right of mid. Otherwise,
// mid may be the minimum, so keep the left half including mid.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    cout << "Input: [3,4,5,1,2]\n";
    cout << "Minimum: " << sol.findMin(nums) << endl;

    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << "Input: [4,5,6,7,0,1,2]\n";
    cout << "Minimum: " << sol.findMin(nums2) << endl;
    return 0;
}

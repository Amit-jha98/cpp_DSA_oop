// 9. Search in Rotated Sorted Array
// Search for target in a rotated sorted array in O(log n).
// Theory / Approach:
// Binary search still works because at least one half of a rotated sorted array
// is sorted. Identify the sorted half and decide whether the target lies there.
//
// Why this works:
// Each step safely discards half of the array: if the target cannot be inside
// the sorted half's range, it must be in the other half.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[lo] <= nums[mid]) { // left half sorted
                if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else { // right half sorted
                if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Input: [4,5,6,7,0,1,2], target=0\n";
    cout << "Index: " << sol.search(nums, 0) << endl;

    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << "Input: [4,5,6,7,0,1,2], target=3\n";
    cout << "Index: " << sol.search(nums2, 3) << endl;
    return 0;
}

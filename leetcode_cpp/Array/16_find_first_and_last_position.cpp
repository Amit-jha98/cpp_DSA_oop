// 16. Find First and Last Position of Element in Sorted Array
// Find the starting and ending position of a given target value, O(log n).
// Theory / Approach:
// Use binary search twice: first to find the first index where nums[i] >= target,
// then to find the first index where nums[i] >= target + 1. The last target is one before that.
//
// Why this works:
// In a sorted array, equal values occupy one continuous block. Lower bounds give
// the left edge of the target block and the left edge of the next larger block.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        if (first == (int)nums.size() || nums[first] != target) return {-1, -1};
        int last = lowerBound(nums, target + 1) - 1;
        return {first, last};
    }
private:
    int lowerBound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> ans = sol.searchRange(nums, 8);
    cout << "Input: [5,7,7,8,8,10], target=8\n";
    cout << "Output: [" << ans[0] << ", " << ans[1] << "]\n";

    vector<int> ans2 = sol.searchRange(nums, 6);
    cout << "Input: [5,7,7,8,8,10], target=6\n";
    cout << "Output: [" << ans2[0] << ", " << ans2[1] << "]\n";
    return 0;
}

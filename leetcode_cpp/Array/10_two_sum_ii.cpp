// 10. Two Sum II - Input Array Is Sorted
// Given a 1-indexed sorted array, find two numbers that add up to target.
// Theory / Approach:
// Since the array is sorted, use two pointers. If the sum is too small, move the
// left pointer right. If the sum is too large, move the right pointer left.
//
// Why this works:
// Moving the smaller value upward is the only way to increase the sum; moving
// the larger value downward is the only way to decrease it.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = (int)numbers.size() - 1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target) return {lo + 1, hi + 1}; // 1-indexed
            else if (sum < target) ++lo;
            else --hi;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2,7,11,15};
    vector<int> ans = sol.twoSum(numbers, 9);
    cout << "Input: [2,7,11,15], target=9\n";
    cout << "Output: [" << ans[0] << ", " << ans[1] << "]\n";
    return 0;
}

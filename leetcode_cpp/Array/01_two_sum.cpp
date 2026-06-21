// 1. Two Sum
// Given an array of integers nums and an integer target, return indices of
// the two numbers such that they add up to target.
//
// Theory / Approach:
// For every number nums[i], the only value that can form the target with it is
// target - nums[i]. So while scanning the array, store numbers already seen in
// a hash map along with their indices.
//
// At each index:
// 1. Compute the required complement: need = target - nums[i].
// 2. If need is already in the map, we found the answer: {index of need, i}.
// 3. Otherwise, store nums[i] with its index for future elements.
//
// Why this works:
// The map represents all numbers to the left of the current index. If a valid
// pair exists, then when we reach the second number of that pair, the first
// number is already stored in the map.
//
// Time Complexity: O(n), because each element is processed once.
// Space Complexity: O(n), for the hash map.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen; // value -> index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            if (seen.count(need)) return {seen[need], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    cout << "Input: nums = [2,7,11,15], target = 9\n";
    cout << "Output: [" << ans[0] << ", " << ans[1] << "]\n";

    vector<int> nums2 = {3, 2, 4};
    vector<int> ans2 = sol.twoSum(nums2, 6);
    cout << "Input: nums = [3,2,4], target = 6\n";
    cout << "Output: [" << ans2[0] << ", " << ans2[1] << "]\n";
    return 0;
}

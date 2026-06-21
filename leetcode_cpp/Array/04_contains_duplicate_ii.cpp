// 4. Contains Duplicate II
// Return true if there are two distinct indices i, j such that
// nums[i] == nums[j] and abs(i - j) <= k.
//
// Theory / Approach:
// This is similar to "Contains Duplicate", but the duplicate must be close
// enough in index distance. Use a hash map from value -> most recent index.
//
// At each index i:
// 1. If nums[i] was seen before, check the distance from its last index.
// 2. If i - last index <= k, return true.
// 3. Update the last index of nums[i] to i.
//
// Why this works:
// For each value, the closest previous duplicate is always its most recent
// occurrence. If the most recent occurrence is farther than k, then any older
// occurrence is even farther and cannot help.
//
// Time Complexity: O(n), because each element is processed once.
// Space Complexity: O(n), for the hash map.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> lastIdx;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (lastIdx.count(nums[i]) && i - lastIdx[nums[i]] <= k) return true;
            lastIdx[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << boolalpha;
    cout << "Input: [1,2,3,1], k=3 -> " << sol.containsNearbyDuplicate(nums, 3) << endl;

    vector<int> nums2 = {1,0,1,1};
    cout << "Input: [1,0,1,1], k=1 -> " << sol.containsNearbyDuplicate(nums2, 1) << endl;
    return 0;
}

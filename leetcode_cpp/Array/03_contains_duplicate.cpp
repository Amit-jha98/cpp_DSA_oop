// 3. Contains Duplicate
// Return true if any value appears at least twice in the array.
//
// Theory / Approach:
// A duplicate exists if we see the same number more than once. Use a hash set to
// remember all numbers already visited.
//
// At each number:
// 1. If it is already in the set, return true immediately.
// 2. Otherwise, insert it into the set and continue.
//
// Why this works:
// The set contains exactly the values seen before the current position. So if
// the current value is already present, it appeared earlier and is a duplicate.
// If the scan finishes without finding such a value, all values are unique.
//
// Time Complexity: O(n), because each lookup/insert is O(1) on average.
// Space Complexity: O(n), for storing seen values.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n)) return true;
            seen.insert(n);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << boolalpha;
    cout << "Input: [1,2,3,1] -> " << sol.containsDuplicate(nums) << endl;

    vector<int> nums2 = {1,2,3,4};
    cout << "Input: [1,2,3,4] -> " << sol.containsDuplicate(nums2) << endl;
    return 0;
}

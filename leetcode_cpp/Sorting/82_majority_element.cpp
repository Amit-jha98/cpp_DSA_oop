// 82. Majority Element
// Find the element that appears more than n/2 times (Boyer-Moore Voting).
// Theory / Approach:
// Use Boyer-Moore voting. Keep a candidate and count; matching values increase
// count, different values decrease it. Reset when count becomes zero.
//
// Why this works:
// Pairing majority and non-majority elements cancels them out. Because the
// majority appears more than half the time, it remains as the final candidate.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int n : nums) {
            if (count == 0) candidate = n;
            count += (n == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << "Input: [2,2,1,1,1,2,2] -> " << sol.majorityElement(nums) << endl;
    vector<int> nums2 = {3,2,3};
    cout << "Input: [3,2,3] -> " << sol.majorityElement(nums2) << endl;
    return 0;
}

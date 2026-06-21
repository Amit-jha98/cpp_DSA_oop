// 49. First Missing Positive
// Find the smallest missing positive integer, in O(n) time, O(1) extra space.
// Theory / Approach:
// Place each value x in index x - 1 when 1 <= x <= n. After this cyclic
// placement, the first index not holding i + 1 gives the answer.
//
// Why this works:
// The smallest missing positive must be in the range 1..n+1. Reordering values
// into their natural indices lets us detect the first gap in one scan.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Place each value v (1<=v<=n) at index v-1
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,0};
    cout << "Input: [1,2,0] -> " << sol.firstMissingPositive(nums) << endl;
    vector<int> nums2 = {3,4,-1,1};
    cout << "Input: [3,4,-1,1] -> " << sol.firstMissingPositive(nums2) << endl;
    vector<int> nums3 = {7,8,9,11,12};
    cout << "Input: [7,8,9,11,12] -> " << sol.firstMissingPositive(nums3) << endl;
    return 0;
}

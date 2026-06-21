// 40. Longest Consecutive Sequence
// Find the length of the longest consecutive elements sequence in O(n).
// Theory / Approach:
// Put all numbers in a hash set. Start counting a sequence only from numbers
// that do not have num - 1 in the set.
//
// Why this works:
// Each consecutive run has exactly one start. Expanding only from starts makes
// every number part of at most one counted run.
//
// Time Complexity: O(n) average
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int best = 0;
        for (int n : numSet) {
            if (!numSet.count(n - 1)) { // n is start of a sequence
                int len = 1;
                int cur = n;
                while (numSet.count(cur + 1)) { ++cur; ++len; }
                best = max(best, len);
            }
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};
    cout << "Input: [100,4,200,1,3,2]\n";
    cout << "Longest Consecutive Sequence: " << sol.longestConsecutive(nums) << endl;
    return 0;
}

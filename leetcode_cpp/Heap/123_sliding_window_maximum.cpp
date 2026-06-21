// 123. Sliding Window Maximum
// Find the maximum value in each sliding window of size k, using a
// monotonic deque.
// Theory / Approach:
// Use a deque of indices with values in decreasing order. Remove indices outside
// the window and remove smaller values from the back before adding a new index.
//
// Why this works:
// The deque front is always the largest valid element in the current window.
// Smaller values behind a newer larger value can never become maximum.
//
// Time Complexity: O(n)
// Space Complexity: O(k)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices, values decreasing
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = sol.maxSlidingWindow(nums, 3);
    cout << "Input: [1,3,-1,-3,5,3,6,7], k=3\nOutput: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

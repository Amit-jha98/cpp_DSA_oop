// 122. Kth Largest Element in an Array
// Find the kth largest element in an unsorted array, using a min-heap
// of size k.
// Theory / Approach:
// Keep a min-heap of size k. Push each number, and if the heap grows beyond k,
// remove the smallest. The heap top is the kth largest.
//
// Why this works:
// After processing all numbers, the heap contains exactly the k largest values,
// with the smallest among them at the top.
//
// Time Complexity: O(n log k)
// Space Complexity: O(k)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int n : nums) {
            minHeap.push(n);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    cout << "Input: [3,2,1,5,6,4], k=2 -> " << sol.findKthLargest(nums, 2) << endl;
    vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    cout << "Input: [3,2,3,1,2,4,5,5,6], k=4 -> " << sol.findKthLargest(nums2, 4) << endl;
    return 0;
}

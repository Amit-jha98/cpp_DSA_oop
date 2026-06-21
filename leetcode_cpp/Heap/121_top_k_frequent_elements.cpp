// 121. Top K Frequent Elements
// Return the k most frequent elements, using a min-heap of size k.
// Theory / Approach:
// Count frequencies with a hash map, then use a heap or bucket strategy to
// select the k values with highest counts.
//
// Why this works:
// Frequency count separates value identity from occurrence count; the selection
// step keeps only the k largest counts.
//
// Time Complexity: O(n log k) with a min-heap
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) freq[n]++;

        auto cmp = [](pair<int,int>& a, pair<int,int>& b) { return a.second > b.second; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);

        for (auto& [num, cnt] : freq) {
            minHeap.push({num, cnt});
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    auto res = sol.topKFrequent(nums, 2);
    cout << "Input: [1,1,1,2,2,3], k=2\nOutput: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

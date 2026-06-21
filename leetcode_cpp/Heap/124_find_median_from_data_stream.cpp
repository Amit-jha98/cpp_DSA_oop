// 124. Find Median from Data Stream
// Design a data structure that supports adding numbers and finding the
// median, using two heaps (max-heap for lower half, min-heap for upper half).
// Theory / Approach:
// Maintain two heaps: a max-heap for the lower half and a min-heap for the upper
// half. Rebalance so their sizes differ by at most one.
//
// Why this works:
// The median is determined by the largest lower-half value and smallest
// upper-half value. The heaps expose those values in O(1).
//
// Time Complexity: O(log n) per add, O(1) per median
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        if (lower.empty() || num <= lower.top()) lower.push(num);
        else upper.push(num);

        // Rebalance: lower can have at most one more than upper
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian() {
        if (lower.size() > upper.size()) return lower.top();
        return (lower.top() + upper.top()) / 2.0;
    }

private:
    priority_queue<int> lower; // max-heap, lower half
    priority_queue<int, vector<int>, greater<int>> upper; // min-heap, upper half
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median after [1,2]: " << mf.findMedian() << endl; // 1.5
    mf.addNum(3);
    cout << "Median after [1,2,3]: " << mf.findMedian() << endl; // 2
    return 0;
}

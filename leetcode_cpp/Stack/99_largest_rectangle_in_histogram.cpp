// 99. Largest Rectangle in Histogram
// Find the area of the largest rectangle in a histogram, using a
// monotonic increasing stack.
// Theory / Approach:
// Use a monotonic increasing stack of bar indices. When a shorter bar appears,
// pop taller bars and compute the rectangle where each popped bar is the height.
//
// Why this works:
// The stack gives the nearest smaller bar on the left, and the current index is
// the nearest smaller bar on the right.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // indices, increasing heights
        int best = 0;
        int n = heights.size();
        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                best = max(best, height * width);
            }
            st.push(i);
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Input: [2,1,5,6,2,3]\n";
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}

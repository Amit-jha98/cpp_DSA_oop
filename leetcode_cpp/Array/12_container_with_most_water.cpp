// 12. Container With Most Water
// Find two lines that together with the x-axis form a container
// that holds the most water.
// Theory / Approach:
// Use two pointers at the ends. The area is limited by the shorter line, so move
// the pointer with the shorter height inward and keep the best area seen.
//
// Why this works:
// Moving the taller line cannot improve the current width-limited container if
// the shorter line stays, so the only useful move is to search for a taller short side.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = (int)height.size() - 1, best = 0;
        while (lo < hi) {
            int area = (hi - lo) * min(height[lo], height[hi]);
            best = max(best, area);
            if (height[lo] < height[hi]) ++lo;
            else --hi;
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Input: [1,8,6,2,5,4,8,3,7]\n";
    cout << "Max Area: " << sol.maxArea(height) << endl;
    return 0;
}

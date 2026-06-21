// 17. Trapping Rain Water
// Compute how much water can be trapped after raining, given elevation map.
// Theory / Approach:
// Use two pointers and track the highest wall seen from both sides. Move the
// side with the smaller current height because that side limits the water level.
//
// Why this works:
// Water above a bar is limited by the shorter boundary. When one side is lower,
// its trapped water can be decided immediately using that side's max.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int lo = 0, hi = n - 1;
        int leftMax = 0, rightMax = 0, water = 0;
        while (lo < hi) {
            if (height[lo] < height[hi]) {
                leftMax = max(leftMax, height[lo]);
                water += leftMax - height[lo];
                ++lo;
            } else {
                rightMax = max(rightMax, height[hi]);
                water += rightMax - height[hi];
                --hi;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Input: [0,1,0,2,1,0,1,3,2,1,2,1]\n";
    cout << "Trapped Water: " << sol.trap(height) << endl;
    return 0;
}

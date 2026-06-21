// 34. Race Car
// Car starts at position 0 with speed +1. 'A' accelerates (pos += speed,
// speed *= 2), 'R' reverses speed (speed = -1 if speed>0 else 1).
// Find length of the shortest sequence of instructions to reach target.
// Theory / Approach:
// Use memoized DP on the target distance. Let n be the number of accelerations
// needed to pass or exactly reach the target. Either hit the target exactly,
// overshoot and reverse, or undershoot, reverse, move back some distance, and
// solve the remaining distance recursively.
//
// Why this works:
// After a run of accelerations, the car is at position 2^k - 1. The optimal
// route can be described by choosing whether to overshoot or undershoot around
// the target, then reusing the same problem on the remaining distance.
//
// Time Complexity: O(target log target) with memoization
// Space Complexity: O(target)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        return solve(target);
    }
private:
    unordered_map<int,int> memo;
    int solve(int target) {
        if (memo.count(target)) return memo[target];
        int n = (int)floor(log2(target)) + 1;
        int res;
        if ((1 << n) - 1 == target) {
            res = n;
        } else {
            // Overshoot then come back
            res = solve((1 << n) - 1 - target) + n + 1;
            // Try undershooting: go n-1 steps, reverse, go m steps, reverse, recurse
            for (int m = 0; m < n - 1; ++m) {
                int cur = (1 << (n - 1)) - (1 << m);
                res = min(res, solve(target - cur) + (n - 1) + m + 1);
            }
        }
        memo[target] = res;
        return res;
    }
};

int main() {
    Solution sol;
    cout << "target=3 -> " << sol.racecar(3) << " (expected 2)" << endl;
    cout << "target=6 -> " << sol.racecar(6) << " (expected 5)" << endl;
    cout << "target=100 -> " << sol.racecar(100) << endl;
    return 0;
}

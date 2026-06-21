// 19. Climbing Stairs
// You can climb 1 or 2 steps at a time. How many distinct ways to climb n steps?
// Theory / Approach:
// To reach step n, the last move came from n - 1 or n - 2. This gives the
// recurrence ways[n] = ways[n - 1] + ways[n - 2], like Fibonacci.
//
// Why this works:
// The two last-move choices are disjoint and cover every valid path, so adding
// their counts gives the total number of ways.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; ++i) {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    cout << "n=2 -> " << sol.climbStairs(2) << endl;
    cout << "n=5 -> " << sol.climbStairs(5) << endl;
    return 0;
}

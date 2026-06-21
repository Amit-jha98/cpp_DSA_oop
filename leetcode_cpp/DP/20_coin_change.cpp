// 20. Coin Change
// Fewest number of coins needed to make up amount, using given coin denominations.
// Theory / Approach:
// Use bottom-up DP where dp[x] is the fewest coins needed to make amount x.
// For every amount, try taking each coin and improve dp[x] from dp[x - coin] + 1.
//
// Why this works:
// The optimal solution for an amount is one coin plus an optimal solution for
// the remaining amount. Building from small amounts guarantees subproblems are ready.
//
// Time Complexity: O(amount * number of coins)
// Space Complexity: O(amount)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int a = 1; a <= amount; ++a) {
            for (int c : coins) {
                if (c <= a && dp[a-c] != INT_MAX) {
                    dp[a] = min(dp[a], dp[a-c] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1,2,5};
    cout << "coins=[1,2,5], amount=11 -> " << sol.coinChange(coins, 11) << endl;
    vector<int> coins2 = {2};
    cout << "coins=[2], amount=3 -> " << sol.coinChange(coins2, 3) << endl;
    return 0;
}

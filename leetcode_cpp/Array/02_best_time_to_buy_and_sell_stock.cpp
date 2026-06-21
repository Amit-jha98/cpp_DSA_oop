// 2. Best Time to Buy and Sell Stock
// Find the maximum profit from one buy and one sell.
//
// Theory / Approach:
// To make a profit, we must buy before we sell. While scanning prices from left
// to right, keep track of the cheapest price seen so far. For each current
// price, pretend we sell today and calculate:
//
// profit = current price - minimum price seen before/today
//
// Update the best profit whenever this profit is larger.
//
// Why this works:
// For any selling day, the best buying day must be the lowest price before that
// day. By maintaining minPrice as we scan, we always know the best possible buy
// price for the current sell day.
//
// If prices only go down, the best profit remains 0 because making no trade is
// better than taking a loss.
//
// Time Complexity: O(n), because we scan the prices once.
// Space Complexity: O(1), because only two variables are used.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, best = 0;
        for (int p : prices) {
            minPrice = min(minPrice, p);
            best = max(best, p - minPrice);
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Input: [7,1,5,3,6,4]\n";
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;

    vector<int> prices2 = {7,6,4,3,1};
    cout << "Input: [7,6,4,3,1]\n";
    cout << "Max Profit: " << sol.maxProfit(prices2) << endl;
    return 0;
}

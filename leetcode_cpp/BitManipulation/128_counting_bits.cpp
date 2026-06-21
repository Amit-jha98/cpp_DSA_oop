// 128. Counting Bits
// For every number i in [0, n], compute the number of 1's in its binary
// representation, in O(n) time using DP.
// Theory / Approach:
// Use DP with the relation bits[i] = bits[i >> 1] + (i & 1). This reuses the
// count for i divided by two and adds the last bit.
//
// Why this works:
// Right shifting removes the least significant bit, so the count differs only by
// whether that removed bit was 1.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.countBits(5);
    cout << "n=5\nOutput: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

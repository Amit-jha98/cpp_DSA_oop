// 29. Pascal's Triangle
// Generate the first numRows of Pascal's triangle.
// Theory / Approach:
// Build rows one by one. The first and last values are 1, and each inner value
// is the sum of the two values above it.
//
// Why this works:
// Pascal's Triangle directly follows the binomial identity C(n,k) = C(n-1,k-1) + C(n-1,k).
//
// Time Complexity: O(numRows^2)
// Space Complexity: O(numRows^2) for the result.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto res = sol.generate(5);
    cout << "numRows=5\n";
    for (auto& row : res) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}

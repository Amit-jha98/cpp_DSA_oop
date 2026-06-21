// 67. Spiral Matrix
// Return all elements of the matrix in spiral order.
// Theory / Approach:
// Maintain top, bottom, left, and right boundaries. Traverse one edge at a time
// and shrink the corresponding boundary after each pass.
//
// Why this works:
// The spiral is exactly the outer layer followed by the spiral of the remaining
// inner submatrix.
//
// Time Complexity: O(mn)
// Space Complexity: O(1) extra space, excluding the result.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[top][j]);
            ++top;
            for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
            --right;
            if (top <= bottom) {
                for (int j = right; j >= left; --j) res.push_back(matrix[bottom][j]);
                --bottom;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
                ++left;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    auto res = sol.spiralOrder(matrix);
    cout << "Spiral Order: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

// 66. Set Matrix Zeroes
// If an element is 0, set its entire row and column to 0, in place,
// using O(1) extra space.
// Theory / Approach:
// Use the first row and first column as marker storage for which rows/columns
// should become zero. Track separately whether the first row/column originally had zeroes.
//
// Why this works:
// Markers record all zeroing decisions before any cells are overwritten, giving
// O(1) extra space while preserving enough information.
//
// Time Complexity: O(mn)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) firstRowZero = true;
        for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) firstColZero = true;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (firstRowZero) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        if (firstColZero) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};

void printMatrix(vector<vector<int>>& m) {
    for (auto& row : m) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "Before:\n"; printMatrix(matrix);
    sol.setZeroes(matrix);
    cout << "After:\n"; printMatrix(matrix);
    return 0;
}

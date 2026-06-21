// 68. Rotate Image
// Rotate an n x n matrix 90 degrees clockwise, in place.
// Theory / Approach:
// Rotate the matrix 90 degrees clockwise by transposing it, then reversing each
// row.
//
// Why this works:
// Transpose moves cell (r, c) to (c, r). Reversing rows changes that to
// (c, n - 1 - r), which is the clockwise rotation position.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
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
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Before:\n"; printMatrix(matrix);
    sol.rotate(matrix);
    cout << "After 90-degree rotation:\n"; printMatrix(matrix);
    return 0;
}

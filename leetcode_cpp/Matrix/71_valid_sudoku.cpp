// 71. Valid Sudoku
// Determine if a 9x9 Sudoku board is valid (each row, column, and 3x3
// sub-box contains digits 1-9 without repetition; '.' means empty).
// Theory / Approach:
// Check each filled digit against three sets of constraints: row, column, and
// 3x3 box. A repeated digit in any constraint makes the board invalid.
//
// Why this works:
// Sudoku validity is exactly the absence of duplicates among filled cells in
// those three constraint groups.
//
// Time Complexity: O(81)
// Space Complexity: O(81)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int boxIdx = (i / 3) * 3 + (j / 3);
                if (rows[i].count(c) || cols[j].count(c) || boxes[boxIdx].count(c)) return false;
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIdx].insert(c);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << boolalpha;
    cout << "Valid Sudoku: " << sol.isValidSudoku(board) << endl;
    return 0;
}

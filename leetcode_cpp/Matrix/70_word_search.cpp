// 70. Word Search
// Determine if a word exists in the grid, constructed from sequentially
// adjacent cells (horizontally or vertically).
// Theory / Approach:
// Use backtracking from every cell that could start the word. Move in four
// directions, marking cells as visited during the current path.
//
// Why this works:
// Each recursive path represents one possible spelling of the word. Temporary
// marking prevents reusing a cell in the same path.
//
// Time Complexity: O(mn * 4^L)
// Space Complexity: O(L)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, const string& word, int idx, int i, int j) {
        if (idx == (int)word.size()) return true;
        if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size() || board[i][j] != word[idx])
            return false;
        char temp = board[i][j];
        board[i][j] = '#'; // mark visited
        bool found = dfs(board, word, idx+1, i+1, j) ||
                     dfs(board, word, idx+1, i-1, j) ||
                     dfs(board, word, idx+1, i, j+1) ||
                     dfs(board, word, idx+1, i, j-1);
        board[i][j] = temp; // restore
        return found;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha;
    cout << "word=\"ABCCED\" -> " << sol.exist(board, "ABCCED") << endl;
    cout << "word=\"SEE\" -> " << sol.exist(board, "SEE") << endl;
    cout << "word=\"ABCB\" -> " << sol.exist(board, "ABCB") << endl;
    return 0;
}

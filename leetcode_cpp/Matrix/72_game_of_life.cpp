// 72. Game of Life
// Update the board to its next state, in place, following Conway's
// Game of Life rules.
// Theory / Approach:
// Count live neighbors for each cell and store the next state in encoded marker
// values so original states are still readable during the pass.
//
// Why this works:
// Each update depends on the original board, not partially updated cells.
// Encoding both old and new states allows in-place simulation.
//
// Time Complexity: O(mn)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        // Encoding: 2 = was alive, now dead. 3 = was dead, now alive.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = countLiveNeighbors(board, i, j, m, n);
                if (board[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) board[i][j] = 2;
                } else {
                    if (liveNeighbors == 3) board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = (board[i][j] == 2) ? 0 : (board[i][j] == 3 ? 1 : board[i][j]);
            }
        }
    }
private:
    int countLiveNeighbors(vector<vector<int>>& board, int i, int j, int m, int n) {
        int count = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (di == 0 && dj == 0) continue;
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && (board[ni][nj] == 1 || board[ni][nj] == 2)) {
                    ++count;
                }
            }
        }
        return count;
    }
};

void printBoard(vector<vector<int>>& b) {
    for (auto& row : b) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    cout << "Before:\n"; printBoard(board);
    sol.gameOfLife(board);
    cout << "After one step:\n"; printBoard(board);
    return 0;
}

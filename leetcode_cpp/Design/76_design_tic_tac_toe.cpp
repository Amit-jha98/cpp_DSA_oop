// 76. Design Tic-Tac-Toe
// Design a Tic-Tac-Toe that supports adding moves and checking the winner
// in O(1) time per move using row/column/diagonal counters.
// Theory / Approach:
// Track row sums, column sums, and two diagonal sums. Add +1 for one player and
// -1 for the other; a win occurs when an absolute sum reaches n.
//
// Why this works:
// A full winning line contains only one player's marks, so its signed sum is
// either n or -n.
//
// Time Complexity: O(1) per move
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class TicTacToe {
public:
    TicTacToe(int n) : n(n), rows(n, 0), cols(n, 0), diag(0), antiDiag(0) {}

    // player is 1 or 2. Returns the winning player, or 0 if no winner yet.
    int move(int row, int col, int player) {
        int val = (player == 1) ? 1 : -1;
        rows[row] += val;
        cols[col] += val;
        if (row == col) diag += val;
        if (row + col == n - 1) antiDiag += val;

        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(antiDiag) == n) {
            return player;
        }
        return 0;
    }

private:
    int n;
    vector<int> rows, cols;
    int diag, antiDiag;
};

int main() {
    TicTacToe game(3);
    cout << "move(0,0,1) -> " << game.move(0, 0, 1) << endl; // 0
    cout << "move(0,2,2) -> " << game.move(0, 2, 2) << endl; // 0
    cout << "move(2,2,1) -> " << game.move(2, 2, 1) << endl; // 0
    cout << "move(1,1,2) -> " << game.move(1, 1, 2) << endl; // 0
    cout << "move(2,0,1) -> " << game.move(2, 0, 1) << endl; // 0
    cout << "move(1,0,2) -> " << game.move(1, 0, 2) << endl; // 0
    cout << "move(2,1,1) -> " << game.move(2, 1, 1) << endl; // 1 (player 1 wins via row 2)
    return 0;
}

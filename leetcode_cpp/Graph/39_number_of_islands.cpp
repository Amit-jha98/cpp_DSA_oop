// 39. Number of Islands
// Count the number of islands ('1' = land, '0' = water) in a 2D grid.
// Theory / Approach:
// Scan the grid. When land is found, count one island and flood-fill all
// connected land cells so they are not counted again.
//
// Why this works:
// DFS/BFS visits exactly one connected component of land. Counting components
// gives the number of islands.
//
// Time Complexity: O(mn)
// Space Complexity: O(mn) worst-case recursion/queue.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '0'; // mark visited
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of Islands: " << sol.numIslands(grid) << endl;
    return 0;
}

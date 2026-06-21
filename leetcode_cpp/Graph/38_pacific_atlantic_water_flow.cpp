// 38. Pacific Atlantic Water Flow
// Find cells from which water can flow to both the Pacific and Atlantic
// oceans (Pacific touches top/left, Atlantic touches bottom/right).
// Theory / Approach:
// Instead of starting from every cell, run DFS/BFS from each ocean border
// backwards to cells with height >= current height. Intersect the reachable sets.
//
// Why this works:
// Reverse traversal marks cells from which water could flow down to that ocean.
// Cells reachable from both oceans satisfy the requirement.
//
// Time Complexity: O(mn)
// Space Complexity: O(mn)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) { dfs(heights, pacific, i, 0); dfs(heights, atlantic, i, n - 1); }
        for (int j = 0; j < n; ++j) { dfs(heights, pacific, 0, j); dfs(heights, atlantic, m - 1, j); }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
        return res;
    }
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < (int)heights.size() && nj >= 0 && nj < (int)heights[0].size()
                && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, ni, nj);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    auto res = sol.pacificAtlantic(heights);
    cout << "Coordinates that can reach both oceans:\n";
    for (auto& c : res) cout << "[" << c[0] << "," << c[1] << "] ";
    cout << endl;
    return 0;
}

// 43. Number of Provinces
// Given an n x n adjacency matrix of cities, find the number of provinces
// (connected components).
// Theory / Approach:
// Treat the adjacency matrix as an undirected graph. Run DFS/BFS from each
// unvisited city and count each connected component as one province.
//
// Why this works:
// Cities in the same connected component are directly or indirectly connected,
// which is exactly the definition of a province.
//
// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++provinces;
                dfs(isConnected, visited, i);
            }
        }
        return provinces;
    }
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < (int)isConnected.size(); ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) dfs(isConnected, visited, j);
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << "Provinces: " << sol.findCircleNum(isConnected) << endl;

    vector<vector<int>> isConnected2 = {{1,0,0},{0,1,0},{0,0,1}};
    cout << "Provinces: " << sol.findCircleNum(isConnected2) << endl;
    return 0;
}

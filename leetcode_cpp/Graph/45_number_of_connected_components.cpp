// 45. Number of Connected Components in an Undirected Graph (LeetCode Premium)
// Given n nodes and a list of undirected edges, count connected components.
// Theory / Approach:
// Build an undirected graph and run DFS/BFS from every unvisited node. Each
// traversal marks one connected component.
//
// Why this works:
// Traversal reaches exactly the nodes connected to the start node. Counting
// starts of traversals counts connected components.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank_;
    DSU(int n) : parent(n), rank_(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto& e : edges) dsu.unite(e[0], e[1]);
        unordered_set<int> roots;
        for (int i = 0; i < n; ++i) roots.insert(dsu.find(i));
        return roots.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    cout << "n=5, edges=[[0,1],[1,2],[3,4]] -> Components: " << sol.countComponents(5, edges) << endl;
    return 0;
}

// 42. Graph Valid Tree (LeetCode Premium)
// Given n nodes labeled 0..n-1 and a list of undirected edges, determine
// if these edges form a valid tree (connected, no cycles).
// Theory / Approach:
// A graph is a tree if it is connected and has exactly n - 1 edges. Use DFS/BFS
// or union-find to confirm all nodes are connected without cycles.
//
// Why this works:
// For an undirected graph, n - 1 edges plus connectivity is equivalent to being
// acyclic and connected.
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
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false; // cycle detected
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1) return false; // tree must have exactly n-1 edges
        DSU dsu(n);
        for (auto& e : edges) {
            if (!dsu.unite(e[0], e[1])) return false; // cycle found
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    cout << "n=5, edges=[[0,1],[0,2],[0,3],[1,4]] -> " << sol.validTree(5, edges) << endl;
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};
    cout << "n=5, edges=[[0,1],[1,2],[2,3],[1,3],[1,4]] -> " << sol.validTree(5, edges2) << endl;
    return 0;
}

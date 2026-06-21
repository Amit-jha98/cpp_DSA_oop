// 35. Clone Graph
// Given a reference to a node in a connected undirected graph, return a
// deep copy (clone) of the graph.
// Theory / Approach:
// Use DFS or BFS with a map from original node to cloned node. Clone each node
// once, then recursively clone and attach its neighbors.
//
// Why this works:
// The map preserves graph identity and prevents infinite loops in cycles. Every
// edge is recreated between the corresponding cloned nodes.
//
// Time Complexity: O(V + E)
// Space Complexity: O(V)
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() { val = 0; neighbors = vector<Node*>(); }
    Node(int _val) { val = _val; neighbors = vector<Node*>(); }
    Node(int _val, vector<Node*> _neighbors) { val = _val; neighbors = _neighbors; }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        return clone(node, visited);
    }
private:
    Node* clone(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.count(node)) return visited[node];
        Node* copy = new Node(node->val);
        visited[node] = copy;
        for (Node* nb : node->neighbors) {
            copy->neighbors.push_back(clone(nb, visited));
        }
        return copy;
    }
};

int main() {
    // Build graph: 1-2-3-4-1 (a square)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution sol;
    Node* cloned = sol.cloneGraph(n1);

    cout << "Original graph adjacency (node 1 BFS):\n";
    // Verify clone via BFS print
    unordered_set<Node*> seen;
    queue<Node*> q;
    q.push(cloned);
    seen.insert(cloned);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " -> ";
        for (Node* nb : cur->neighbors) cout << nb->val << " ";
        cout << endl;
        for (Node* nb : cur->neighbors) {
            if (!seen.count(nb)) { seen.insert(nb); q.push(nb); }
        }
    }
    cout << "Clone successful, different pointer: " << (cloned != n1 ? "true" : "false") << endl;
    return 0;
}

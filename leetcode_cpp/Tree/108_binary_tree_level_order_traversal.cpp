// 108. Binary Tree Level Order Traversal
// Return the level order traversal of a binary tree's node values
// (left to right, level by level).
// Theory / Approach:
// Use BFS with a queue. Process the queue level by level, collecting all nodes
// currently in the queue as one level.
//
// Why this works:
// BFS visits nodes in increasing distance from the root, which matches level
// order traversal.
//
// Time Complexity: O(n)
// Space Complexity: O(width)
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    auto res = sol.levelOrder(root);
    for (auto& level : res) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
    return 0;
}

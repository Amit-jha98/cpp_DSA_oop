// 116. Binary Tree Zigzag Level Order Traversal
// Return the zigzag level order traversal (left-to-right, then
// right-to-left for the next level, alternating).
// Theory / Approach:
// Run normal BFS by levels, but reverse the collected values on alternating
// levels or insert them in opposite directions.
//
// Why this works:
// Zigzag traversal keeps the same level grouping as BFS; only the output order
// within every other level changes.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                int idx = leftToRight ? i : sz - 1 - i;
                level[idx] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
            leftToRight = !leftToRight;
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
    auto res = sol.zigzagLevelOrder(root);
    for (auto& level : res) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
    return 0;
}

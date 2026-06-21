// 111. Find Leaves of Binary Tree
// Collect and remove leaves repeatedly until the tree is empty, grouping
// nodes removed at the same "round" together.
// Theory / Approach:
// Compute each node's height from the bottom. Leaves have height 0, and a node's
// height is 1 plus the max height of its children. Group nodes by height.
//
// Why this works:
// Removing leaves layer by layer is equivalent to grouping nodes by their
// distance upward from the nearest leaf layer.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        height(root, res);
        return res;
    }
private:
    int height(TreeNode* node, vector<vector<int>>& res) {
        if (!node) return -1;
        int h = 1 + max(height(node->left, res), height(node->right, res));
        if ((int)res.size() == h) res.push_back({});
        res[h].push_back(node->val);
        return h;
    }
};

int main() {
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    auto res = sol.findLeaves(root);
    cout << "Leaves removed by round:\n";
    for (auto& round : res) {
        for (int x : round) cout << x << " ";
        cout << endl;
    }
    return 0;
}

// 107. Binary Tree Maximum Path Sum
// Find the maximum path sum, where a path may start and end at any node
// (not necessarily the root).
// Theory / Approach:
// DFS returns the best downward path starting at each node. At each node, update
// the global answer with left gain + node value + right gain.
//
// Why this works:
// A complete path can bend at one node, but the value returned to a parent must
// continue in only one direction.
//
// Time Complexity: O(n)
// Space Complexity: O(h)
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
    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        maxGain(root);
        return best;
    }
private:
    int best;
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        best = max(best, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
};

int main() {
    //   -10
    //   /  \
    //  9   20
    //     /  \
    //    15   7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Max Path Sum: " << sol.maxPathSum(root) << endl; // expect 42
    return 0;
}

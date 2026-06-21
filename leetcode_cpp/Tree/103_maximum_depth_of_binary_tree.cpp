// 103. Maximum Depth of Binary Tree
// Find the maximum depth (number of nodes along the longest path from
// root to leaf).
// Theory / Approach:
// Use DFS. The depth of a node is 1 plus the maximum depth of its left and right
// subtrees; an empty subtree has depth 0.
//
// Why this works:
// The longest root-to-leaf path must go through either the left child or right
// child, so taking the larger subtree depth gives the answer.
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    //     3
    //    / \
    //   9   20
    //      /  \
    //     15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Max Depth: " << sol.maxDepth(root) << endl;
    return 0;
}

// 106. Invert/Flip Binary Tree
// Invert a binary tree (mirror it).
// Theory / Approach:
// Recursively swap the left and right child of every node. Return the root after
// both subtrees have been inverted.
//
// Why this works:
// Mirroring a tree is a local operation at every node: swap children, then mirror
// the subtrees.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    //     4
    //    / \
    //   2   7
    //  / \ / \
    // 1  3 6  9
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout << "Before (inorder): "; printInorder(root); cout << endl;
    sol.invertTree(root);
    cout << "After invert (inorder): "; printInorder(root); cout << endl;
    return 0;
}

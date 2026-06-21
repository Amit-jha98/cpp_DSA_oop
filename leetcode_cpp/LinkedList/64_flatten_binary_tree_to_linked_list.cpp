// 64. Flatten Binary Tree to Linked List
// Flatten a binary tree into a "linked list" in place, following
// preorder traversal, using the right child pointer as 'next'.
// Theory / Approach:
// Flatten the tree in preorder by rewiring each node's left subtree between the
// node and its original right subtree.
//
// Why this works:
// Preorder visits node, left, then right. Moving the left chain to the right and
// attaching the old right subtree after its tail preserves that order.
//
// Time Complexity: O(n)
// Space Complexity: O(h) recursion stack or O(1) for iterative rewiring.
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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* rightmost = cur->left;
                while (rightmost->right) rightmost = rightmost->right;
                rightmost->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);
    cout << "Flattened (preorder): "; printFlattened(root);
    return 0;
}

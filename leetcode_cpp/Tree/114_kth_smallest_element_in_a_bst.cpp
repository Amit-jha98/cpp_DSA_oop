// 114. Kth Smallest Element in a BST
// Find the kth smallest value in a binary search tree, using inorder
// traversal (which visits values in sorted order).
// Theory / Approach:
// Inorder traversal of a BST visits values in sorted order. Count visited nodes
// until reaching the kth one.
//
// Why this works:
// The BST property guarantees left subtree values, then root, then right subtree
// values form ascending order.
//
// Time Complexity: O(h + k)
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) { st.push(cur); cur = cur->left; }
            cur = st.top(); st.pop();
            if (--k == 0) return cur->val;
            cur = cur->right;
        }
        return -1; // not found (invalid k)
    }
};

int main() {
    //     3
    //    / \
    //   1   4
    //    \
    //     2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    cout << "k=1 -> " << sol.kthSmallest(root, 1) << endl;
    cout << "k=2 -> " << sol.kthSmallest(root, 2) << endl;
    return 0;
}

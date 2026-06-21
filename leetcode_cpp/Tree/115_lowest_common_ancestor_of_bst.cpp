// 115. Lowest Common Ancestor of a Binary Search Tree
// Find the lowest common ancestor of two nodes in a BST.
// Theory / Approach:
// Use BST ordering. If both target values are smaller than the current node, go
// left; if both are larger, go right. Otherwise, current node is the split point.
//
// Why this works:
// The first node where the paths to p and q diverge is their lowest common
// ancestor.
//
// Time Complexity: O(h)
// Space Complexity: O(1)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (cur) {
            if (p->val < cur->val && q->val < cur->val) cur = cur->left;
            else if (p->val > cur->val && q->val > cur->val) cur = cur->right;
            else return cur;
        }
        return nullptr;
    }
};

int main() {
    //         6
    //       /   \
    //      2     8
    //     / \   / \
    //    0   4 7   9
    //       / \
    //      3   5
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    Solution sol;
    TreeNode* p = root->left;             // 2
    TreeNode* q = root->right;            // 8
    cout << "LCA(2,8) = " << sol.lowestCommonAncestor(root, p, q)->val << endl;

    TreeNode* p2 = root->left;            // 2
    TreeNode* q2 = root->left->right;     // 4
    cout << "LCA(2,4) = " << sol.lowestCommonAncestor(root, p2, q2)->val << endl;
    return 0;
}

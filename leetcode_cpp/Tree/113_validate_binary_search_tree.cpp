// 113. Validate Binary Search Tree
// Determine if a binary tree is a valid binary search tree (BST).
// Theory / Approach:
// Validate each node with an allowed value range. Left children must be strictly
// smaller than the node, and right children strictly larger.
//
// Why this works:
// BST validity is global, not just parent-child. Passing bounds down the tree
// enforces all ancestor constraints.
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
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool validate(TreeNode* node, long long lower, long long upper) {
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;
        return validate(node->left, lower, node->val) && validate(node->right, node->val, upper);
    }
};

int main() {
    //   2
    //  / \
    // 1   3
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    //   5
    //  / \
    // 1   4
    //    / \
    //   3   6
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    Solution sol;
    cout << boolalpha;
    cout << "Tree 1 valid BST: " << sol.isValidBST(root1) << endl; // true
    cout << "Tree 2 valid BST: " << sol.isValidBST(root2) << endl; // false
    return 0;
}

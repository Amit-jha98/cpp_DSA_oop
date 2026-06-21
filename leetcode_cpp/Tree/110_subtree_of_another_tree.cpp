// 110. Subtree of Another Tree
// Determine if subRoot is a subtree of root (a tree consisting of a node
// in root and all its descendants matches subRoot exactly).
// Theory / Approach:
// For each node in the main tree, check whether the tree rooted there is exactly
// the same as subRoot.
//
// Why this works:
// A subtree must start at some node of the main tree. Same-tree comparison
// verifies both structure and values from that starting point.
//
// Time Complexity: O(mn) worst case
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return !subRoot;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
};

int main() {
    //       3
    //      / \
    //     4   5
    //    / \
    //   1   2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    //   4
    //  / \
    // 1   2
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    cout << boolalpha;
    cout << "Is Subtree: " << sol.isSubtree(root, subRoot) << endl;
    return 0;
}

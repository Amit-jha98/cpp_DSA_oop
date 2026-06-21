// 105. Symmetric Tree
// Determine if a binary tree is a mirror of itself around its center.
// Theory / Approach:
// Compare the left and right subtrees as mirrors. The outside children must
// match each other, and the inside children must match each other.
//
// Why this works:
// A symmetric tree has matching values at mirrored positions around the root.
// Recursive mirror comparison checks exactly those pairs.
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};

int main() {
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    cout << boolalpha;
    cout << "Symmetric: " << sol.isSymmetric(root) << endl;
    return 0;
}

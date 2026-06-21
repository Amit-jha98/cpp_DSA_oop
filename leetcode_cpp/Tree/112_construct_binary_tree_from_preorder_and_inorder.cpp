// 112. Construct Binary Tree from Preorder and Inorder Traversal
// Build a binary tree given its preorder and inorder traversal arrays.
// Theory / Approach:
// Preorder gives the root first. Use the root's index in inorder to split left
// and right subtrees, then recursively build each side.
//
// Why this works:
// Inorder lists all left subtree nodes before the root and all right subtree
// nodes after it. Preorder tells which root to place next.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < (int)inorder.size(); ++i) inorderIdx[inorder[i]] = i;
        preIdx = 0;
        return build(preorder, 0, (int)inorder.size() - 1);
    }
private:
    int preIdx;
    unordered_map<int,int> inorderIdx;
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderIdx[rootVal];
        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);
        return root;
    }
};

void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    cout << "Rebuilt tree (preorder check): "; printPreorder(root); cout << endl;
    return 0;
}

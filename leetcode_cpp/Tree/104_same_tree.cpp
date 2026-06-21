// 104. Same Tree
// Determine if two binary trees are structurally identical with the
// same node values.
// Theory / Approach:
// Recursively compare both trees. Two nodes match only if both are null, or both
// exist with equal values and matching left/right subtrees.
//
// Why this works:
// Trees are identical exactly when their roots and corresponding subtrees are
// identical.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    cout << boolalpha;
    cout << "Same Tree: " << sol.isSameTree(p, q) << endl;

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    cout << "Different structure: " << sol.isSameTree(p, r) << endl;
    return 0;
}

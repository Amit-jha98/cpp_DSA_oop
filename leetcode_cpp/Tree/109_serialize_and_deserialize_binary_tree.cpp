// 109. Serialize and Deserialize Binary Tree
// Design an algorithm to serialize a binary tree to a string, and
// deserialize it back to the original tree (using preorder + null markers).
// Theory / Approach:
// Serialize with preorder traversal and include markers for null children.
// Deserialize by reading tokens in the same preorder sequence.
//
// Why this works:
// Preorder plus explicit null markers uniquely describes the shape and values of
// the tree.
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

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return build(iss);
    }
private:
    TreeNode* build(istringstream& iss) {
        string token;
        getline(iss, token, ',');
        if (token == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = build(iss);
        node->right = build(iss);
        return node;
    }
};

void printPreorder(TreeNode* root) {
    if (!root) { cout << "# "; return; }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string data = codec.serialize(root);
    cout << "Serialized: " << data << endl;

    TreeNode* restored = codec.deserialize(data);
    cout << "Restored (preorder): "; printPreorder(restored); cout << endl;
    return 0;
}

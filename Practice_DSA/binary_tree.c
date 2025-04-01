#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct bTree {
    int data;
    struct bTree *left;
    struct bTree *right;
};

// Function to create a new node
struct bTree *createNode(int value) {
    struct bTree *newNode = malloc(sizeof(struct bTree));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node in the binary tree (Binary Search Tree Insertion)
struct bTree *insert(struct bTree *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// In-order Traversal (Left-Root-Right)
void inorderTraversal(struct bTree *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Pre-order Traversal (Root-Left-Right)
void preorderTraversal(struct bTree *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Post-order Traversal (Left-Right-Root)
void postorderTraversal(struct bTree *root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct bTree *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

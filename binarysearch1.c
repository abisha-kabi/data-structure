#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new key into the BST
struct TreeNode* insert(struct TreeNode* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct TreeNode* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->key);
        preorder(node->left);
        preorder(node->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct TreeNode* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->key);
    }
}

// Main function to demonstrate the BST and its traversals
int main() {
    struct TreeNode* root = NULL;
    int n, key;

    // Ask the user for the number of nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Insert nodes into the BST based on user input
    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    // Perform traversals
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}                                                                                         

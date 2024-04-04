#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    
    cout << root->val << " "; // Print the value of the current node
    
    preOrder(root->left); // Recursively traverse the left subtree
    preOrder(root->right); // Recursively traverse the right subtree
}

// Example usage:
int main() {
    // Create the sample binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(6);
    root->right->right->left->right = new TreeNode(4);
    
    // Call the preOrder function to print the preorder traversal of the binary tree
    preOrder(root);
    
    return 0;
}

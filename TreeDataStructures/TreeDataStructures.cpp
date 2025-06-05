#include <iostream>

// Node structure for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary tree class
class BinaryTree {
private:
    TreeNode* root;

    // Helper function for inserting a node recursively
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }

        return node;
    }

    // Helper function for in-order traversal recursively
    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function for deleting a node recursively
    TreeNode* deleteNode(TreeNode* node, int val) {
        if (node == nullptr) {
            return node;
        }

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        }
        else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        }
        else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Public function to insert a value into the tree
    void insert(int val) {
        root = insert(root, val);
    }

    // Public function to perform in-order traversal
    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    // Public function to delete a value from the tree
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }
};

// Example usage
int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "In-order traversal: ";
    tree.inorderTraversal();

    tree.deleteNode(30);

    std::cout << "In-order traversal after deleting 30: ";
    tree.inorderTraversal();

    return 0;
}

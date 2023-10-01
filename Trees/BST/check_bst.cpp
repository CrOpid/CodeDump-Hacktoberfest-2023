#include <iostream>
#include <climits>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBST(TreeNode* root, int minValue = INT_MIN, int maxValue = INT_MAX) {
    if (root == nullptr) {
        return true;
    }

    if (root->data < minValue || root->data > maxValue) {
        return false;
    }

    return isBST(root->left, minValue, root->data - 1) && isBST(root->right, root->data + 1, maxValue);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    if (isBST(root)) {
        std::cout << "The binary tree is a BST." << std::endl;
    } else {
        std::cout << "The binary tree is not a BST." << std::endl;
    }

    return 0;
}

#include <iostream>

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    TreeNode *root;

public:
    BST() : root(nullptr) {}

    void insert(int val)
    {
        root = insertRecursive(root, val);
    }

    void remove(int val)
    {
        root = removeRecursive(root, val);
    }

    bool search(int val)
    {
        return searchRecursive(root, val);
    }

    void preOrderTraversal()
    {
        preOrderTraversalRecursive(root);
        std::cout << std::endl;
    }

private:
    TreeNode *insertRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < node->data)
        {
            node->left = insertRecursive(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    TreeNode *removeRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (val < node->data)
        {
            node->left = removeRecursive(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = removeRecursive(node->right, val);
        }
        else
        {
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            TreeNode *temp = findMinValueNode(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }

        return node;
    }

    TreeNode *findMinValueNode(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    bool searchRecursive(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (val == node->data)
        {
            return true;
        }
        else if (val < node->data)
        {
            return searchRecursive(node->left, val);
        }
        else
        {
            return searchRecursive(node->right, val);
        }
    }

    void preOrderTraversalRecursive(TreeNode *node)
    {
        if (node != nullptr)
        {
            std::cout << node->data << " ";
            preOrderTraversalRecursive(node->left);
            preOrderTraversalRecursive(node->right);
        }
    }
};

int main()
{
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.preOrderTraversal();

    int searchValue = 40;
    if (bst.search(searchValue))
    {
        std::cout << searchValue << " found in the BST." << std::endl;
    }
    else
    {
        std::cout << searchValue << " not found in the BST." << std::endl;
    }

    int removeValue = 30;
    bst.remove(removeValue);
    bst.preOrderTraversal();

    return 0;
}

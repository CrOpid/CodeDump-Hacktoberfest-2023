/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* root, long minval, long maxval ){

        if(root==NULL) return true;

        if(root->val >= maxval || root->val <= minval) return false;

        return check(root->left,minval, root->val) && check(root->right, root->val, maxval);


    }
};F
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
    bool isValid(TreeNode* root, int min, int max) {
        if (!root) return true;
        if (root->val > min && root->val < max) return isValid(root->right, root->val, max) && isValid(root->left, min, root->val);
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, -INT_MAX, INT_MAX); 
    }
};

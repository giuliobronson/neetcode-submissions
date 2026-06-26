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
    int diameter = 0;

    int deep(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int right = deep(root->right); 
        int left  = deep(root->left); 
        diameter = max(diameter, right + left);
        return max(right, left) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        deep(root);
        return diameter;
    }
};

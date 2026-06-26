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
    bool balance = true;

    int deep(TreeNode* root) {
        if (!root) return 0;
        int right = deep(root->right);
        int left  = deep(root->left);
        balance = balance ? abs(right - left) <= 1 : false; 
        return max(right, left) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        deep(root);
        return balance;
    }
};

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
    int deep(TreeNode* root, int len) {
        if (!root) return len - 1;
        if (!root->right && !root->left) return len;
        return max(deep(root->left, len + 1), deep(root->right, len + 1));
    }

    int maxDepth(TreeNode* root) {
        return deep(root, 1);
    }
};

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
    bool searchNode(TreeNode* root, TreeNode* target) {
        if (!root) return false;
        if (target->val == root->val) {
            return true;
        }
        if (target->val > root->val) {
            return searchNode(root->right, target);
        }
        return searchNode(root->left, target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (searchNode(root->left, p) && searchNode(root->left, q)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(searchNode(root->right, p) && searchNode(root->right, q)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

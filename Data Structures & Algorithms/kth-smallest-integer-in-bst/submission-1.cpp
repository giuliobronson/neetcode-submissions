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
    int i = 0, found = -1;

    int kthSmallest(TreeNode* root, int k) {
        index(root, k);
        return found;
    }

    void index(TreeNode* root, int k) {
        if (!root || found != -1) return;

        index(root->left,  k);
        if (++i == k) found = root->val;
        index(root->right, k);
    }
};

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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr) {
                TreeNode* temp = curr->right;
                curr->right = curr->left;
                curr->left = temp;
                q.push(curr->right);
                q.push(curr->left);
            }
        }

        return root;
    }
};

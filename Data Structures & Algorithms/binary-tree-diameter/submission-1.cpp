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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        stack<TreeNode*> s, v;
        int diameter = 0;

        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();
            if (curr->right && !m.count(curr->right)) {
                s.push(curr->right);
            }
            else if (curr->left && !m.count(curr->left)) {
                s.push(curr->left);
            }
            else {
                s.pop();
                int right = m.count(curr->right) ? m[curr->right] : 0;
                int left  = m.count(curr->left)  ? m[curr->left]  : 0;
                diameter = max(right + left, diameter);
                m[curr]  = max(right, left) + 1;
            }
        } 

        return diameter;
    }
};

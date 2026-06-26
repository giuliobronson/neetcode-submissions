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
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*, int> height;
        stack<TreeNode*> s;

        if (!root) return true;

        s.push(root);
        while (!s.empty()) {
            TreeNode* curr = s.top();

            if (curr->right && !height.count(curr->right)) {
                s.push(curr->right);
            }
            else if (curr->left && !height.count(curr->left)) {
                s.push(curr->left);
            }
            else {
                s.pop();
                int right = height.count(curr->right) ? height[curr->right] : 0;
                int left  = height.count(curr->left)  ? height[curr->left]  : 0;
                if (abs(right - left) > 1) return false;
                height[curr] = max(right, left) + 1;
            }
        }

        return true;
    }
};

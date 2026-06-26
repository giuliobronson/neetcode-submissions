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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        int maxLen = 0;

        s.push({root, 1});
        while (!s.empty()) {
            auto [curr, len] = s.top(); s.pop();
            if (curr) {
                if (!curr->right && !curr->left) {
                    maxLen = max(maxLen, len);
                    continue;
                }
                s.push({curr->left, len + 1});
                s.push({curr->right, len + 1});
            }
        }

        return maxLen;
        
    }
};

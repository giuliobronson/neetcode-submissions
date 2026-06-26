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
        queue<pair<TreeNode*, int>> q;
        int maxLen = 0;

        q.push({root, 1});
        while (!q.empty()) {
            auto [curr, len] = q.front(); q.pop();
            if (curr) {
                if (!curr->right && !curr->left) {
                    maxLen = max(maxLen, len);
                    continue;
                }
                q.push({curr->right, len + 1});
                q.push({curr->left, len + 1});
            }
        }

        return maxLen;
    }
};

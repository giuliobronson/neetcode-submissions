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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<int> res;
        int currLevel = 0;

        q.push({root, 1});
        while (!q.empty()) {
            auto [curr, level] = q.front(); q.pop();

            if (curr) {
                if (currLevel != level) {
                    res.push_back(curr->val);
                    currLevel = level;
                }
                q.push({curr->right, level + 1});
                q.push({curr->left, level + 1});
            }
        }

        return res;
    }
};

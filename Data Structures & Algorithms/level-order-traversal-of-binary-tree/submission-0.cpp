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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res = {};
        vector<int> level = {};
        queue<pair<TreeNode*, int>> q;
        int currStage = 0;

        q.push({root, 0}); 
        while (!q.empty()) {
            auto [curr, stage] = q.front(); q.pop();

            if (currStage != stage) {
                res.push_back(level);
                level = {};
                currStage = stage;
            }
            if (curr) {
                level.push_back(curr->val);
                q.push({curr->left, stage + 1});
                q.push({curr->right, stage + 1});
            }
        }

        return res;
    }
};

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> s;

        s.push({p, q});
        while (!s.empty()) {
            auto [currP, currQ] = s.top(); s.pop();

            if (currP && !currQ || !currP && currQ) {
                return false;
            }
            else if (currP && currQ) {
                if (currP->val != currQ->val) {
                    return false;
                }
                s.push({currP->right, currQ->right});
                s.push({currP->left, currQ->left});
            }
        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSameTree(root, subRoot)) return true;
        if (root) {
            return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
        }
        return false;
    }
};

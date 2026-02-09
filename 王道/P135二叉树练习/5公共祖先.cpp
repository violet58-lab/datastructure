/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *result = NULL;
        auto dfs = [&](auto &self, TreeNode *root) ->bool 
        {
            if(root == NULL) return false;
            bool fl = self(self,root->left);
            bool fr = self(self,root->right);
            if(fl && fr || (root == p || root == q) && (fl || fr)) result = root;
            return fl || fr || (root == p || root == q);
        };
        dfs(dfs,root);
        return result;
    }
};
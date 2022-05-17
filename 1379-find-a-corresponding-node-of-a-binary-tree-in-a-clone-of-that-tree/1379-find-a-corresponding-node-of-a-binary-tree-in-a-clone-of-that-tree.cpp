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
    void solve(TreeNode* root, int t, TreeNode* &ans){
        if(!root) return;
        if(root->val == t)ans = root;
        solve(root->left,t,ans);
        solve(root->right,t,ans);
    }
    TreeNode* getTargetCopy(TreeNode* og, TreeNode* cl, TreeNode* t) {
        TreeNode* ans = NULL;
        solve(cl,t->val,ans);
        return ans;
    }
};
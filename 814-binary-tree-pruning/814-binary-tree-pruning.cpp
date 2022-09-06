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
    bool solve(TreeNode* root){
        if(!root)return false;
        if(!root->left and !root->right)return root->val == 1;
        bool l = solve(root->left);
        bool r = solve(root->right);
        if(!l)root->left = NULL;
        if(!r) root->right = NULL;
        
        return l || r || root->val == 1;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!solve(root))return NULL;
        return root;
    }
};
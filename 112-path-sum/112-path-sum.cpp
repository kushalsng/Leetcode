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
    bool fun(TreeNode* root, int targetSum, int sum){
        if(!root) return false;
        if(!root->left && !root->right){
            if(targetSum == sum+root->val)return true;
            return false;
        }
        
        return fun(root->left, targetSum, sum + root->val) ||
            fun(root->right, targetSum, sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val == targetSum) return true;
        bool a = fun(root->left, targetSum, root->val);
        bool b = fun(root->right, targetSum, root->val);
        
        if(!root->left && root->val == targetSum) return b;
        else if(!root->right && root->val == targetSum) return a;
        
        return a || b;
    }
};
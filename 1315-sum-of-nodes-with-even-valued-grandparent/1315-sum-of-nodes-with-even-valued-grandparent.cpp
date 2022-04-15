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
    void sum(TreeNode* root, int &ans){
        if(!root)return;
        if(!root->left && !root->right) return;
        if(root->val % 2 == 0){
            if(root->left){
                if(root->left->left) ans += root->left->left->val;
                if(root->left->right) ans += root->left->right->val;
                
            }
            if(root->right) {
                if(root->right->left)ans += root->right->left->val;
                if(root->right->right)ans += root->right->right->val;
                
            }
        }
        sum(root->left, ans);
        sum(root->right, ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans =0;
        sum(root, ans);
        
        return ans;
    }
};
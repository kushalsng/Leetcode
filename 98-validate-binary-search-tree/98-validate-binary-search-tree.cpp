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
    bool solve(TreeNode* root, long lb, long ub){
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(root->left && root->right){
            if((root->left->val >= root->val) || (root->right->val <= root->val)) return false;
            if(root->left->val <= lb) return false;
            if(root->right->val >= ub) return false;
        }else {
            if(root->left){
                if(root->left->val >= root->val) return false;
                if(root->left->val <= lb) return false;
            }
            if(root->right){
                if(root->right->val <= root-> val) return false;
                if(root->right->val >= ub) return false;
            }
        }
        return solve(root->left,lb, (long)root->val) && solve(root->right,(long) root->val, ub);
    }
    bool isValidBST(TreeNode* root) {
//         if(!root) return true;
//         if(!root->left && !root->right) return true;
//         if(root->left && root->right){
//             if((root->left->val >= root->val) || (root->right->val <= root->val)) return false;
//         }else {
//             if(root->left){
//                 if(root->left->val >= root->val) return false;
//             }
//             if(root->right){
//                 if(root->right->val <= root-> val) return false;

//             }
//         }
        
        return solve(root,LONG_MIN, LONG_MAX);
    }
};
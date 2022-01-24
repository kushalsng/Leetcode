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
    int fun(TreeNode* root, bool* isBal){
        if(!root) return 0;
        int l = fun(root->left, isBal);
        int r = fun(root->right, isBal);
        if(abs(l-r) > 1) *isBal = false;
        return max(l, r) + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        bool isBal = true;
        fun(root, &isBal);
        return isBal;
    }
};
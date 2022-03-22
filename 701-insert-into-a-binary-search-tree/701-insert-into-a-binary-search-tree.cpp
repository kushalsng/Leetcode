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
    void insert(TreeNode* root, TreeNode* n){
        if(!root) return;
        if(root->val > n->val) {
            if(root->left)insert(root->left, n);
            else root->left = n;
            return;
        }
        if(root->val < n->val) {
            if(root->right)insert(root->right, n);
            else root->right = n;
            return;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* n = new TreeNode(val);
        if(!root) return n;
        insert(root, n);
        return root;
    }
};
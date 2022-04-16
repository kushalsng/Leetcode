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
    int sum(TreeNode* root){
        if(!root) return 0;
        int sm=0;
        sm += sum(root->left);
        sm += root->val;
        sm += sum(root->right);
        return sm;
    }
    void solve(TreeNode* &root, int &sum){
        if(!root) return;
        solve(root->left, sum);
        sum -= root->val;
        root->val += sum;
        solve(root->right, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sm = sum(root);
        solve(root, sm);
        return root;
    }
};
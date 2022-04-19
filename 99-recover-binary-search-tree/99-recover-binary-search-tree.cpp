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
    void inorder(TreeNode* &root, vector<TreeNode*> &v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        int n = v.size();
        int i=0,j=n-1;
        while(v[i]->val <= v[i+1]->val)i++;
        // i--;
        while(v[j-1]->val <= v[j]->val)j--;
        // j++;
        swap(v[i]->val, v[j]->val);
    }
};
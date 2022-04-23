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
    void del(TreeNode* &root, int key, TreeNode* parent) {
        if(!root) return;
        if(root->val == key){
            if(root->left && root->right){
                TreeNode* ptr = root->left;
                while(ptr->right)ptr = ptr->right;
                ptr->right = root->right;
                root->right = NULL;
                root = root->left;
            }else if(root->left) root = root->left;
            else if(root->right) root = root->right;
            else{
                if(parent){
                    if(parent->left == root) parent->left = NULL;
                    else if(parent->right == root) parent->right = NULL;
                }
                root=NULL;
            }
            return;
        }
        if(root->val > key)del(root->left,key,root);
        else del(root->right,key,root);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root,key,NULL);
        return root;
    }
};
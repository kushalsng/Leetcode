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
    void inorder(TreeNode* &root, TreeNode* &prev, TreeNode* &first, TreeNode* &second){
        if(!root) return;
        inorder(root->left, prev, first, second);
        if(prev != NULL && root->val <= prev->val){
            if(first == NULL)first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right, prev, first, second);
    }
    void recoverTree(TreeNode* root) {
        // vector<TreeNode*> v;
        TreeNode* prev = NULL;
        TreeNode* first = NULL, *second = NULL;
        inorder(root, prev,first, second);
        swap(first->val, second->val);
        // int n = v.size();
        // int i=0,j=n-1;
        // while(v[i]->val <= v[i+1]->val)i++;
        // // i--;
        // while(v[j-1]->val <= v[j]->val)j--;
        // // j++;
        // swap(v[i]->val, v[j]->val);
    }
};
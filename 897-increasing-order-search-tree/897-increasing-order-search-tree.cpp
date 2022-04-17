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
    list<int> inorder(TreeNode* root, list<int> &x){
        if(!root) return x;
        inorder(root->left, x);
        x.push_back(root->val);
        inorder(root->right, x);
        return x;
    }
    TreeNode* increasingBST(TreeNode* root) {
        list<int> x;
        x = inorder(root, x);
        root->val = x.front();
        x.pop_front();
        TreeNode* ptr = root;
        while(!x.empty()){
            ptr->left = NULL;
            ptr->right = new TreeNode(x.front());
            x.pop_front();
            ptr = ptr->right;
        }
        ptr = root;
        while(ptr){
            cout<<ptr->val<<" ";
            ptr = ptr->right;
        }
        return root;
    }
};
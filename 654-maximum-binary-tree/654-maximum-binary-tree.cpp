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
    TreeNode* solve(vector<int> in,int l,int r){
        if(l>r)return NULL;
        int mx = in[l];
        int x=l;
        
        for(int i=l; i<=r; i++){
            if(in[i] > mx){
                mx=in[i];
                x = i;
            }
        }
        TreeNode* root = new TreeNode(in[x]);
        
        root->left = solve(in,l,x-1);
        root->right = solve(in,x+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& in) {
        return solve(in,0,in.size()-1);
    }
};
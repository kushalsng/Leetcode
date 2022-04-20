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
    int pi = 1;
    TreeNode* solve(vector<int>& post, vector<int>& in,int n, int l, int r){
        if(l>r)return NULL;
        TreeNode* root = new TreeNode(post[n-pi]);
        pi++;
        int x;
        for(int i=l; i<=r; i++){
            if(root->val == in[i]){
                x=i;
                break;
            }
        }
        root->right = solve(post,in,n,x+1,r);
        root->left = solve(post,in,n,l,x-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        return solve(post,in,in.size(),0,in.size()-1);
    }
};
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
    int preInd = 0;
    TreeNode* solve(vector<int> pre, vector<int> in, int l, int r){
        if(l>r) return NULL;
        TreeNode* root = new TreeNode(pre[preInd++]);
        int x;
        for(int i=l; i<=r; i++){
            if(in[i] == root->val){
                x = i;
                break;
            }
        }
        root->left = solve(pre, in, l, x-1);
        root->right = solve(pre, in, x+1, r);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in = pre;
        sort(in.begin(),in.end());
        return solve(pre,in,0,in.size()-1);
    }
};
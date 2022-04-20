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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i=0;i<x;i++){
                TreeNode* ptr = q.front();
                q.pop();
                if(i==x-1)ans.push_back(ptr->val);
                if(ptr->left)q.push(ptr->left);
                if(ptr->right)q.push(ptr->right);
            }
        }
        return ans;
    }
};
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
    void solve(TreeNode* root, int target, vector<vector<int>>& ans, vector<int> &v){
        if(!root)return;
        if(!root->left and !root->right){
            v.push_back(root->val);
            if(target == root->val)ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        solve(root->left, target - root->val, ans, v);
        // v.pop_back();
        solve(root->right, target - root->val, ans, v);
        
        v.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        if(!root)return ans;
        if(!root->left and !root->right and root->val == target){
            ans.push_back({root->val});
            return ans;
        } 
        vector<int> v;
        v.push_back(root->val);
        solve(root->left,target - root->val,ans,v);
        solve(root->right, target - root->val, ans, v);
        return ans;
    }
};
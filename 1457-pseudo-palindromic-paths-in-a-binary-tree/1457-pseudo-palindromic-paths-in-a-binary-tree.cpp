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
    void solve(TreeNode* root, unordered_map<int,int> &mp, int& ans){
        if(!root)return;
        if(!root->left and !root->right){
            mp[root->val]++;
            int ones=0;
            for(auto it=mp.begin(); it!= mp.end(); it++){
                if(it->second %2)ones++;
            }
            if(ones <=1)ans++;
            mp[root->val]--;
            if(mp[root->val] == 0)mp.erase(root->val);
            return;
        }
        mp[root->val]++;
        solve(root->left, mp,ans);
        solve(root->right,mp,ans);
        mp[root->val]--;
        if(mp[root->val] == 0)mp.erase(root->val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        int ans=0;
        solve(root,mp,ans);
        return ans;
    }
};
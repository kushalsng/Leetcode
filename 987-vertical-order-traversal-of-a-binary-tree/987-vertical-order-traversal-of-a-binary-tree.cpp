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
    // void solve(TreeNode* root, int h, map<int,vector<int>> &mp){
    //     if(!root) return;
    //     mp[h].push_back(root->val);
    //     solve(root->left, h-1, mp);
    //     solve(root->right, h+1, mp);
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        // solve(root, 0, mp);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            map<int,vector<int>> submp;
            int x =q.size();
            for(int i=0; i<x; i++){
                pair<TreeNode*,int> p = q.front();
                q.pop();
                int h = p.second;
                TreeNode* ptr = p.first;
                // mp[h].push_back(ptr->val);
                submp[h].push_back(ptr->val);
                if(p.first->left != NULL)q.push({p.first->left, p.second-1});
                if(p.first->right != NULL)q.push({p.first->right, p.second+1});
            }
            
            for(auto it = submp.begin(); it != submp.end(); it++){
                int hh = it->first;
                vector<int> v = it->second;
                sort(v.begin(),v.end());
                for(auto num: v) mp[hh].push_back(num);
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            // sort(it->second.begin(), it->second.end());
            ans.push_back(it->second);
        }
        return ans;
    }
};
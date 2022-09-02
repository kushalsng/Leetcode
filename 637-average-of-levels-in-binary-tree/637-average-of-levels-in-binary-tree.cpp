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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int cnt=q.size();
            double tans = 0.0;
            for(int i=0; i<cnt; i++){
                TreeNode* p = q.front();
                q.pop();
                tans += (double)p->val;
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            ans.push_back((double)tans/cnt);
        }
        return ans;
    }
};
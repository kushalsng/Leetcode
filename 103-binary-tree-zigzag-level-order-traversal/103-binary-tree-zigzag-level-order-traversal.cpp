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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        bool toggle = false;
        q.push(root);
        while(!q.empty()){
            stack<TreeNode*> s;
            int cnt = q.size();
            vector<int> v;
            for(int i=0; i<cnt; i++){
                TreeNode* ptr = q.front();
                q.pop();
                if(toggle)s.push(ptr);
                else v.push_back(ptr->val);
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
            if(toggle){
                while(!s.empty()){
                    v.push_back(s.top()->val);
                    s.pop();
                }
            }
            toggle = !toggle;
            ans.push_back(v);
        }
        return ans;
    }
};
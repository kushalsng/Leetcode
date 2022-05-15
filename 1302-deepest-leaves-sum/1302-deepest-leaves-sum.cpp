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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int sz = q.size();
            bool dpst = true;
            int tans=0;
            for(int i=0; i<sz; i++){
                TreeNode* ptr = q.front();
                q.pop();
                tans += ptr->val;
                if(ptr->left){
                    q.push(ptr->left);
                    dpst = false;
                }
                if(ptr->right){
                    q.push(ptr->right);
                    dpst = false;
                }
            }
            if(dpst)ans += tans;
            
        }
        return ans;
    }
};
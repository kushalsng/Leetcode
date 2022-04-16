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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int lvl=1;
        pair<long long,int> p = {LONG_LONG_MIN,0};
        q.push(root);
        while(!q.empty()){
            int c = q.size();
            long long sum=0;
            for(int i=0;i<c;i++){
                TreeNode* ptr = q.front();
                q.pop();
                sum += ptr->val;
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
            if(sum > p.first){
                p.first= sum;
                p.second = lvl;
            }
            lvl++;
        }
        return p.second;
    }
};
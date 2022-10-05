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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * n = new TreeNode(val);
            n->left = root;
            return n;
        }
        queue<TreeNode*> q;
        q.push(root);
        int dep = 1;
        while(!q.empty()){
            int sz = q.size();
            dep++;
            for(int i=0;i<sz;i++){
                TreeNode* ptr = q.front();
                q.pop();
                if(dep == depth){
                    // if(ptr->left){
                        TreeNode* n = new TreeNode(val);
                        n->left = ptr->left;
                        ptr->left = n;
                    // }
                    // if(ptr->right){
                        n = new TreeNode(val);
                        n->right = ptr->right;
                        ptr->right = n;
                    // }
                }
                // else{
                    if(ptr->left)q.push(ptr->left);
                    if(ptr->right)q.push(ptr->right);
                // }
                
            }
        }
        return root;
    }
};
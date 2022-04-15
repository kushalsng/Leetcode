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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ind = 0;
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz; i++){
                TreeNode* ptr = q.front();
                // cout<<ptr->val<<" ";
                q.pop();
                if(ind%2 == ptr->val%2)return false;
                else{
                    if(i<sz-1){
                        TreeNode* t = q.front();
                        if(t->val%2 == ind%2) return false;
                        // cout<<ptr->val<<" "<<t->val<<endl;
                        if(ind%2){
                            if(ptr->val <= t->val) return false;
                        }else{
                            if(ptr->val >= t->val) return false;
                        }
                    }
                    // cout<<ind<<" "<<ptr->val<<" "<<q.empty()<<endl;
                }
                if(ptr->left)q.push(ptr->left);
                if(ptr->right)q.push(ptr->right);
            }
            // cout<<"new line "<<ind<<endl;
            ind++;
        }
        return true;
    }
};
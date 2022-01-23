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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        TreeNode* ptr = root;
        list<TreeNode*> l;
        int sum = 0;
        l.push_back(NULL);
        while(ptr){
            if(ptr->right) {
                    l.push_back(ptr->right);
                }
            
            
            if(ptr->left){
                if(!ptr->left->left && !ptr->left->right) {
                    sum+= ptr->left->val;
                }
                ptr=ptr->left;
            }
            else{
                ptr = l.back();
                l.pop_back();
            }
        }
        return sum;
    }
};
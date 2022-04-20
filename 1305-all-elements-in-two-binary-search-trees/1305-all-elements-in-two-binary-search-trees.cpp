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
    void solve(TreeNode* root,vector<int> &v){
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                v.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr)prev = prev->right;
                
                if(!prev->right){
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    prev->right = NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        // TreeNode *ptr1 == root1,*pt2==root2;
        solve(root1,ans);
        solve(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
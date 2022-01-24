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
    typedef long long int ll;
    ll append(ll main, ll dig) {
        return (main*10 + dig);
    }
    
    ll fun(TreeNode* root, ll sum, ll temp){
        if(!root) return 0;
        temp = append(temp, root->val);
        
        if(!root->left && !root->right){
            sum += temp;
            return sum;
        }
        return fun(root->left, sum, temp) + fun(root->right, sum, temp);
    }
    int sumNumbers(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        
        return fun(root->left, 0, root->val) + fun(root->right, 0, root->val);
    }
};
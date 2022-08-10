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
    TreeNode* fun(TreeNode* root, ll l, ll r, vector<int>& nums){
        if(l>r) return root;
        ll mid = (l+r)/2;
        TreeNode* nw = new TreeNode(nums[mid]);
        root = nw;
        root->left = fun(root->left, l, mid-1, nums);
        root-> right = fun(root->right, mid+1, r, nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        ll l = 0, r = nums.size() - 1;
        TreeNode* root= NULL;
        
        return fun(root, l, r, nums);
    }
};
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
class FindElements {
public:
    unordered_set<int> us;
    void solve(TreeNode* &root){
        if(!root) return;
        if(root->left){
            root->left->val = root->val*2 +1;
            us.insert(root->left->val);
            solve(root->left);
        }
        if(root->right) {
            root->right->val = root->val*2 +2;
            us.insert(root->right->val);
            solve(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        us.insert(0);
        solve(root);
    }
    
    bool find(int target) {
        return us.find(target) != us.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
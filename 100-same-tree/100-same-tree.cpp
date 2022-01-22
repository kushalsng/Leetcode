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
    void check(TreeNode* p, TreeNode* q, bool* same){
        if(!p && !q) return;
        if((p && !q) || (q && !p)){
            *same = false;
            return;
        }
        if(p->val != q->val) {
            *same = false;
            return;
        }
        if((p->left && !q->left) || (q->left && !p->left)){
            *same = false;
            return;
        }
        if(p->left && q->left){
            if(p->left->val != q->left->val){
                *same = false;
                return;
            }
        }
        if((p->right && !q->right) || (q->right && !p->right)) {
            *same = false;
            return;
        }
        if(p->right &&  q->right){
            if(p->right->val != q->right->val) {
                *same = false;
                return;
            }
        }
        
        check(p->left, q->left, same);
        check(p->right, q->right, same);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same = true;
        check(p,q, &same);
        return same;
    }
};
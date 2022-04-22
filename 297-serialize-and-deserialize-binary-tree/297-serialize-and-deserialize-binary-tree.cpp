/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void pre(TreeNode* root, string &ans){
        if(!root){
            ans+="#/";
            return;
        }
        ans += to_string(root->val)+"/";
        pre(root->left, ans);
        pre(root->right,ans);
    }
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans="/";
        pre(root,ans);
        return ans;
    }
    TreeNode* solve(string s,int &l, int &r){
        if(l>s.size()) return NULL;
        cout<<l<<" "<<r<<endl;
        if(s[l] == '#'){
            return NULL;
        }
        string t="";
        for(int i=l; i<r; i++)t+= s[i];
        TreeNode* root = new TreeNode(stoi(t));
        l = r+1;
        r=l;
        while(s[r] != '/')r++;
        root->left = solve(s,l, r);
        root->right = solve(s,l,r);
        return root;
    }
    string empty= "#";
    int ind=0;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(!s.size())return NULL;
        if(ind >= s.size()-1)return NULL;
        string t = "";
        while(s[++ind] != '/')t += s[ind];
        cout<<t<<" ";
        if(t == empty)return NULL;
        TreeNode* root = new TreeNode(stoi(t));
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
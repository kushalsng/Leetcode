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
        if(!root) return;
        ans+= to_string(root->val) + "/";
        pre(root->left, ans);
        pre(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "/";
        pre(root, ans);
        return ans;
    }

    TreeNode* solve(vector<int> pre,vector<int> in, int &pi, int l, int r){
        if(l>r)return NULL;
        TreeNode* root = new TreeNode(pre[pi++]);
        int x;
        for(int i=l; i<=r; i++){
            if(root->val == in[i]){
                x=i;break;
            }
        }
        root->left = solve(pre,in,pi,l,x-1);
        root->right = solve(pre,in,pi,x+1,r);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        TreeNode* root = NULL;
        if(!s.size())return root;
        int j=0;
        vector<int> pre;
        while(j<s.size()){
            if(s[j]=='/')s.erase(s.begin()+j);
            else{
                int i=j;
                j++;
                while(s[j]!='/')j++;
                string t="";
                for(int k=i; k<j;k++)t+=s[k];
                pre.push_back(stoi(t));
            }
        }
        vector<int> in = pre;
        sort(in.begin(),in.end());
        int pi=0;
        return solve(pre,in,pi, 0, pre.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
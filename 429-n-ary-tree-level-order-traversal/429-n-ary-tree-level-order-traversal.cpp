/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            int x= q.size();
            for(int i=0; i<x; i++){
                Node* ptr = q.front();
                q.pop();
                v.push_back(ptr->val);
                for(auto child: ptr->children)if(child)q.push(child);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
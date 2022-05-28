class Solution {
public:
    void dfs(int x, vector<int> &vis, vector<vector<int>>& adj, vector<vector<int>> &ans, vector<int> &v, int n){
        vis[x] = 1;
        v.push_back(x);
        for(auto node: adj[x]){
            if(!vis[node]){
                dfs(node, vis,adj,ans,v, n);
            }
        }
        vis[x]=0;
        if(x == n-1){
            ans.push_back(v);
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> ans;
        vector<int> v, vis(n+1);
        if(!vis[0]){
            dfs(0,vis, adj, ans, v, n);
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(int x, int p, vector<vector<int>>& ans,vector<int>& vis, vector<int> adj[],vector<int>& low,vector<int>& in,int &timer){
        vis[x] = 1;
        low[x] = in[x] = timer++;
        for(auto node: adj[x]){
            if(node == p)continue;
            else if(vis[node]){
                low[x] = min(low[x], in[node]);
            }else{
                dfs(node,x, ans,vis,adj, low,in,timer);
                low[x] = min(low[x], low[node]);
                if(low[node] > in[x]){
                    ans.push_back({x,node});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0), low(n,0), in(n,0);
        vector<vector<int>>ans;
        vector<int> adj[n];
        int timer=0;
        for(auto con: connections){
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        vis[0] = 1;
        low[0] = in[0] = timer++;
        for(auto node: adj[0]){
            if(vis[node]){
                low[0] = min(low[0], in[node]);
            }else{
                dfs(node,0, ans,vis,adj, low,in,timer);
                low[0] = min(low[0], low[node]);
                if(low[node] > in[0]){
                    ans.push_back({0,node});
                }
            }
        }
        return ans;
    }
};
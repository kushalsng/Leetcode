class Solution {
public:
    void dfs(int x, int &cnt, vector<int> &vis, vector<int> adj[]){
        vis[x]=1;
        cnt++;
        for(int node: adj[x]){
            if(!vis[node]){
                dfs(node,cnt,vis,adj);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        int m = edges.size();
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n),len;
        long long ans=0,sum=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int cnt=0;
                dfs(i,cnt,vis,adj);
                len.push_back(cnt);
                sum += cnt;
            }
        }
        m = len.size();
        for(int i=0; i<m-1; i++){
            sum -= len[i];
            ans += (sum*len[i]);
        }
        return ans;
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                queue<int> q;
                q.push(i);
                vis[i] = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto x: graph[node]){
                        if(vis[x] == -1){
                            q.push(x);
                            if(vis[node] == 0) vis[x] = 1;
                            else vis[x] =0;
                        }else if(vis[x] == vis[node]) return false;
                        
                    }
                }
            }
        }
        return true;
    }
};
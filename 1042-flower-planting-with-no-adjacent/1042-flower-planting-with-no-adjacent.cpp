class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        vector<int> vis(n, 0);
        for(auto path: paths){
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        for(int i=1; i<=n; i++){
            if(!vis[i-1]){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    for(int j=1; j<=4; j++){
                        bool isThere = true;
                        for(auto node: adj[x]){
                            if(vis[node-1] == j)isThere = false;
                        }
                        if(isThere){
                            vis[x-1] = j;
                            break;
                        }
                    }
                    for(auto node: adj[x]){
                        if(!vis[node-1]){
                            q.push(node);
                        }
                    }
                }
            }
        }
        return vis;
    }
};
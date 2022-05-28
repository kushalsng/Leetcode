class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size(), ans=0;
        vector<int> vis(n+1);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    for(int j=0; j<adj[x].size(); j++){
                        if(adj[x][j] && !vis[j]){
                            vis[j] =1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
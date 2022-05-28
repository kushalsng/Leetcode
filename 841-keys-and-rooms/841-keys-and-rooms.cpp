class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n);
        queue<int> q;
        q.push(0);
        vis[0]= 1;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto x: adj[i]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        for(auto x: vis) if(!x) return false;
        return true;
    }
};
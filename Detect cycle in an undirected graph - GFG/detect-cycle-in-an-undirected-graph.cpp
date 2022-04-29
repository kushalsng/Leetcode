// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycleCheck(int x, vector<int> adj[],vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({x,-1});
        vis[x] = true;
        while(!q.empty()){
            int cur = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it: adj[cur]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it,cur});
                }else{
                    if(it != par)return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V+1,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(cycleCheck(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
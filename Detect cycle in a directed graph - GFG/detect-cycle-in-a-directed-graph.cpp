// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indeg(V);
        queue<int> q;
        int cnt =0;
        for(int i=0; i<V; i++){
            for(auto x: adj[i]) indeg[x]++;
        }
        for(int i=0; i<V; i++){
            if(!indeg[i])q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            cnt++;
            for(auto node: adj[x]){
                indeg[node]--;
                if(indeg[node] == 0) q.push(node);
            }
        }
        return !(V == cnt);
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
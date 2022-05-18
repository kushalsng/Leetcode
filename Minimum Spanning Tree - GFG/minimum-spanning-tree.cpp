// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

using pii = pair<int,int>;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> mst(V,false);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // key[0] = 0;
        // par[0] = -1;
        int ans=0;
        pq.push({0,0});
        while(!pq.empty()){
            int u = pq.top().second;
            int cost= pq.top().first;
            pq.pop();
            if(!mst[u]) mst[u] = true;
            else continue;
            ans += cost;
            for(auto x: adj[u]){
                int v = x[0], w = x[1];
                if(!mst[v]){
                    // key[v] = w;
                    pq.push({w,v});
                    // par[v] = u;
                }
            }
        }
        
        // for(auto x: key)ans += x;
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
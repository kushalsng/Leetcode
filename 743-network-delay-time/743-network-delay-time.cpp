typedef pair<int,int> pi;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pi> adj[n+1];
        for(auto t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            pi p = pq.top();
            pq.pop();
            // vis[p.first] = 1;
            for (auto to : adj[p.second]) {
                 int adjn= to.first, time = to.second;
                if (dist[adjn] > dist[p.second] + time) {
                    dist[adjn] = dist[p.second] + time;
                    pq.push({dist[adjn], adjn});
                }
            }
        }
        long long ans = INT_MIN;
        for(int i=1; i<=n; i++){
            ans = max<long long>(ans,dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string,bool> vis;
    double qans;
public:
    bool dfs(string start, string end, double runningprod){
        if(start == end and adj.find(start) != adj.end()){
            qans = runningprod;
            return true;
        }
        bool tans = false;
        vis[start] = true;
        
        for(int i=0; i<adj[start].size(); i++){
            if(!vis[adj[start][i].first]){
                tans = dfs(adj[start][i].first, end, runningprod * adj[start][i].second);
                if(tans)break;
            }
        }
        vis[start] = false;
        
        return tans;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& qs) {
        for(int i=0; i<eq.size(); i++){
            string u = eq[i][0], v = eq[i][1];
            double w = val[i];
            adj[u].push_back({v,w});
            w = 1/w;
            adj[v].push_back({u,w});
            vis[u]=false, vis[v] = false;
        }
        vector<double>ans(qs.size(), -1.0);
        
        for(int i=0; i<qs.size(); i++){
            qans = 1;
            bool found = dfs(qs[i][0], qs[i][1], 1);
            if(found)ans[i] = qans;
            else ans[i] = -1;
        }
        return ans;
    }
};
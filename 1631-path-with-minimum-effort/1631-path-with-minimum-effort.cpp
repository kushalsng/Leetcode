class Solution {
    vector<vector<int>> dirs = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        using pipii = pair<int,pair<int,int>>;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        int rows = mat.size(), cols = mat[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int weight = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(dist[r][c] < weight) continue;
            if(r == rows -1 && c == cols-1)return weight;
            for(auto &dir: dirs){
                int dr = r + dir[0];
                int dc = c + dir[1];
                if(dr< 0 || dr >=rows)continue;
                if(dc<0 || dc >= cols) continue;
                int nw = abs(mat[r][c] - mat[dr][dc]);
                nw = max(nw,weight);
                if(nw >= dist[dr][dc])continue;
                dist[dr][dc] = nw;
                pq.push({nw,{dr,dc}});
            }
        }
        return 0;
    }
};
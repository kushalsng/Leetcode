class Solution {
    using pipii = pair<int,pair<int,int>>;
    vector<int> dx = {-1,0,1,0,-1,-1,1,1}, dy = {0,-1,0,1,-1,1,-1,1};
    int m,n;
    // int vis[101][101];
    bool isValid(int x,int y){
        return (x>=0 && x<m && y>=0 && y<n);
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        // memset(vis,0,sizeof vis);
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        pq.push({1,{0,0}});
        dist[0][0] = 1;
        while(!pq.empty()){
            int dp = pq.top().first, ip = pq.top().second.first, jp = pq.top().second.second;
            pq.pop();
            
            for(int i=0; i<8; i++){
                int a = ip + dx[i], b = jp + dy[i];
                if(isValid(a,b) && grid[a][b] == 0){
                    if(dist[a][b] > dp+1){
                        // cout<<a<<" "<<b<<", ";
                        dist[a][b] = dp+1;
                        pq.push({dist[a][b], {a,b}});
                    }
                }
            }
        }
        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1];
    }
};
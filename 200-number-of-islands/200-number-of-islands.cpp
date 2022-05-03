class Solution {
    vector<int> dx{-1,0,1,0}, dy{0,-1,0,1};
    // int vis[301][301];
    int m,n;
public:
    bool isValid(int x,int y){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    void dfs(int x, int y, vector<vector<char>> &grid){
        // vis[x][y] = 1;
        grid[x][y] = '0';
        for(int i=0; i<4; i++){
            int a = x+ dx[i], b = y+dy[i];
            if(isValid(a,b)){
                if(grid[a][b] == '1'){
                    dfs(a,b,grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        // memset(vis,0,sizeof vis);
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
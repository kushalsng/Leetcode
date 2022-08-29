class Solution {
public:
    int m,n;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    bool isValid(int x,int y){
        return (x<m && x>=0 && y<n && y>=0);
    }
    void dfs(int x,int y,vector<vector<int>> &vis, vector<vector<int>>& grid, vector<vector<int>>& grid1, bool &isVal){
        vis[x][y] = 1;
        if(grid1[x][y] == 0){
            // cout<<x<<" "<<y<<", ";
            isVal = false;
            // return;
        }
        for(int i=0; i<4; i++){
            int a = x+dx[i], b =y+dy[i];
            if(isValid(a,b) && !vis[a][b] && grid[a][b]){
                dfs(a,b, vis, grid, grid1, isVal);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]){
                    bool isVal = true;
                    dfs(i,j,vis,grid, grid1,isVal);
                    if(isVal)ans++;
                }
            }
        }
        return ans;
    }
};
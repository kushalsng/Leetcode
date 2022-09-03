class Solution {
public:
    int m,n;
    int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
    bool isValid(int x,int y){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    void dfs(int x,int y, vector<vector<int>>& vis, vector<vector<int>>& grid, bool &isVal){
        vis[x][y]=1;
        if(x == 0 || y == 0 || x == m-1 || y == n-1)isVal = false;
        
        for(int i=0;i<4; i++){
            int a = x+dx[i], b = y+dy[i];
            if(isValid(a,b) && !vis[a][b] && !grid[a][b]){
                dfs(a,b, vis,grid,isVal);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans=0;
        for(int i=1; i<m-1; i++){
            for(int j=1;j<n-1; j++){
                if(!vis[i][j] && !grid[i][j]){
                    bool isVal=true;
                    dfs(i,j,vis,grid,isVal);
                    if(isVal)ans++;
                }
            }
        }
        return ans;
    }
};
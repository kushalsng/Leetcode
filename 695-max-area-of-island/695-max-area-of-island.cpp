class Solution {
    vector<int> dx{-1,0,1,0}, dy{0,-1,0,1};
public:
    bool isValid(int x,int y, int m, int n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    void dfs(int x, int y, int m, int n, vector<vector<int>> grid, vector<vector<int>> &vis, int &tans){
        vis[x][y] = true;
        tans++;
        for(int i=0; i<4; i++){
            int a = x + dx[i], b = y+ dy[i];
            if(isValid(a,b,m,n)){
                if(!vis[a][b] && grid[a][b])
                    dfs(a,b,m,n,grid,vis,tans);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0, m=grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int tans=0;
                if(!vis[i][j] && grid[i][j])
                    dfs(i,j,m,n,grid,vis,tans);
                if(tans) cout<<tans<<" ";
                ans = max(tans,ans);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0 && grid[i][j] != 1)dp[i][j] = 1;
                else if(grid[i][j] == 1)dp[i][j] = 0;
                else{
                    int u=0,l=0;
                    if(i>0) u = dp[i-1][j];
                    if(j>0) l = dp[i][j-1];
                    dp[i][j] = u+l;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
class Solution {
public:
    int f(int i,int j,int m, int n, vector<vector<int>> grid,vector<vector<int>>&dp){
        if(i == m-1 && j== n-1)return grid[i][j];
        if(i == m || j == n) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        
        int r,d;
        r = f(i+1,j,m,n,grid,dp);
        d = f(i,j+1,m,n,grid,dp);
        return dp[i][j] = min(r,d) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i == m-1 && j== n-1) dp[i][j] = grid[i][j];
                else{
                    int r = INT_MAX, d = INT_MAX;
                    if(i<m-1) r  = dp[i+1][j];
                    if(j<n-1) d = dp[i][j+1];
                    dp[i][j] = min(r,d) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};
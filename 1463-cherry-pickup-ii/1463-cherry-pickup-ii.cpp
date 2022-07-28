class Solution {
public:
    int m,n;
    int f(int i, int j1, int j2, vector<vector<int>> grid, vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n || i<0) return -1e8;
        if(i == m-1){
            // return 0;
            if(j1 == j2)return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int mx = -1e8;
        for(int x = -1; x<=1; x++){
            for(int y= -1; y<=1; y++){
                int val =0;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];
                val += f(i+1, j1+x, j2+y, grid, dp);
                mx = max(mx, val);
            }
        }
        dp[i][j1][j2] = mx;
        return mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,0)));
        
        for(int j1 =0; j1<n;j1++){
            for(int j2 = 0; j2<n; j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }

        for(int i = m-2; i>=0; i--){
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int mx = -1e8;
                    for(int x = -1; x<=1; x++){
                        for(int y= -1; y<=1; y++){
                            int val =0;
                            if(j1 == j2) val = grid[i][j1];
                            else val = grid[i][j1] + grid[i][j2];
                            if(j1+x>=0 && j1+x<n && j2+y>=0 && j2+y<n)
                                val += dp[i+1][j1+x][j2+y];
                            else val += -1e8;
                            
                            mx = max(mx, val);
                        }
                    }
                    dp[i][j1][j2] = mx;
                }
            }
        }
        return dp[0][0][n-1];
    }
};
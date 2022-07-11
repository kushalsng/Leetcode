class Solution {
public:
    // int f(int i,int j, int m, int n, vector<vector<int>> & grid){
    //     if(i == m-1 && j<n && j>=0)return grid[i][j];
    //     if(j<0 || j>= n)return INT_MAX;
    //     int a = f(i+1, j-1, m,n,grid);
    //     int b = f(i+1,j,m,n, grid);
    //     int c = f(i+1,j+1,m,n,grid);
    //     // cout<<a<<" "<<b<<" "<<c<<", ";
    //     return min({a,b,c}) + grid[i][j];
    // }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int j=0; j<n;j++){
            dp[m-1][j] = grid[m-1][j];
        }
        for(int k=n-1; k>=0; k--){
            for(int i=m-2; i>=0; i--){
                for(int j=n-1; j>=0; j--){
                    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
                    if(j>0) a = dp[i+1][j-1];
                    if(j<n-1) b = dp[i+1][j+1];
                    c = dp[i+1][j];
                    // cout<<a<<" "<<b<<" "<<c<<", ";
                    dp[i][j] = min({a,b,c}) + grid[i][j];
                }
            }
            ans = min(ans, dp[0][k]);
        }
        return ans;
    }
};
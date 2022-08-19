class Solution {
public:
    int dp[101][101][202];
    bool f(int i,int j, int k, int m,int n, vector<vector<char>>& grid){
        if(i>=m || j>=n)return false;
        
        if(grid[i][j] == '(')k++;
        else k--;
        
        if(i==m-1 && j == n-1)return k==0;
        
        if(k<0)return false;
        
        if(dp[i][j][k] != -1)return dp[i][j][k];
        
        return dp[i][j][k] = (f(i+1,j,k,m,n,grid) || f(i,j+1, k, m,n, grid));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        memset(dp, -1, sizeof dp);
        return f(0,0,0,m,n,grid);
    }
};
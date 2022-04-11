class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        while(k--){
            int save = grid[0][0];
            for(int i=m-1; i>=0; i--){
                for(int j=n-1; j>=0;j--){
                    if(i==m-1 && j==n-1) grid[0][0] = grid[i][j];
                    else if(j == n-1) grid[i+1][0] = grid[i][j];
                    // esle if(i==0 && j==1)grid[i][j] = save;
                    else grid[i][j+1] = grid[i][j];
                }
            }
            if(n>1) grid[0][1] = save;
            else if(m>1)grid[1][0] = save;
        }
        return grid;
    }
};
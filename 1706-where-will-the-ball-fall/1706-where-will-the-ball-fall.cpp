class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n,-1);
        for(int j=0;j<n;j++){
            int i=0, k = j;
            while(i<m){
                if(k == 0 and grid[i][k] == -1)break;
                if(k == n-1 and grid[i][k] == 1)break;
                
                if(grid[i][k] == 1){
                    if(grid[i][k+1] == 1){
                        i++,k++;
                    }else break;
                }else {
                    if(grid[i][k-1] == -1){
                        i++,k--;
                    }else break;
                }
            }
            if(i == m)ans[j] = k;
        }
        return ans;
    }
};
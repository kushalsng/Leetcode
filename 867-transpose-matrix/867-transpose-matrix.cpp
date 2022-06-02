class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& grid) {
        int i=0,j=0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans;
        while(j<n){
            vector<int> v;
            while(i<m){
                v.push_back(grid[i++][j]);
            }
            ans.push_back(v);
            i=0;
            j++;
        }
        return ans;
    }
};
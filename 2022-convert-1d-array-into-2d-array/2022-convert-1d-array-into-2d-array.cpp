class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& og, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        if(m*n != og.size())return {};
        int p=0;
        for(int i=0;i<m; i++){
            for(int j=0;j<n;j++){
                ans[i][j] = og[p++];
            }
        }
        return ans;
    }
};
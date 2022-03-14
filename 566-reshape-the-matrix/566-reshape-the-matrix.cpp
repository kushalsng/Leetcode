class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rr = mat.size(), cc= mat[0].size();
        
        if(rr*cc != r*c) return mat;
        vector<vector<int>> ans;
        int ii=0, jj=0;
        for(int i=0; i<r;i++){
            ans.push_back(vector<int>(c));
            for(int j=0; j<c; j++){
                // cout<<mat[ii][jj]<<endl;
                ans[i][j]= mat[ii][jj++];
                if(jj>=cc)ii++,jj=0;
                if(ii == rr) break;
            }
        }
        return ans;
    }
};
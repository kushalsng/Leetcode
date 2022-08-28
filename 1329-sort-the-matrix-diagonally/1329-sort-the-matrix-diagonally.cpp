class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m =mat.size(), n = mat[0].size();
        for(int k=n-1; k>=0; k--){
            vector<int> v;
            int i=0,j=k;
            while(i<m && j<n){
                v.push_back(mat[i++][j++]);
            }
            sort(v.begin(),v.end());
            i=0,j=k;
            int ind=0;
            while(i<m && j<n && ind<v.size()){
                mat[i++][j++] = v[ind++];
            }
        }
        for(int k=1; k<m; k++){
            vector<int> v;
            int i=k,j=0;
            while(i<m && j<n){
                v.push_back(mat[i++][j++]);
            }
            sort(v.begin(),v.end());
            i=k,j=0;
            int ind=0;
            while(i<m && j<n && ind<v.size()){
                mat[i++][j++] = v[ind++];
            }
        }
        return mat;
    }
};
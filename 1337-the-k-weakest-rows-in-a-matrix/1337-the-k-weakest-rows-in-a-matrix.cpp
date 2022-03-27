class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        for(int i =0; i<mat.size(); i++){
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        for(int i=0; i<k; i++){
            ans.push_back(mat[i].back());
        }
        return ans;
    }
};
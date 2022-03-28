class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int k) {
        int m = mt.size(),n = mt[0].size();
        int i=0, j= n-1;
        while(i>=0 && i<m && j>=0 && j<n){
            if(mt[i][j] == k) return true;
            else if(mt[i][j] > k) --j;
            else ++i;
        }
        return false;
    }
};
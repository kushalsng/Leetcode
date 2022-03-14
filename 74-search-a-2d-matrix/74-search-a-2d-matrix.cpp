class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int k) {
        int m = mt.size(),n = mt[0].size();
        
        for(int i=0; i<m; i++){
            int l=0,r=n-1;
            while(l<=r){
                int mid = l+ (r-l)/2;
                if(mt[i][mid] == k) return true;
                else if(mt[i][mid] > k) r = mid-1;
                else{
                    l= mid+1;
                }
            }
        }
        return false;
    }
};
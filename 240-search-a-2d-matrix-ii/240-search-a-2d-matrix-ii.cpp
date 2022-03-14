class Solution {
public:
    typedef long long ll;
    bool searchMatrix(vector<vector<int>>& mt, int k) {
        ll m = mt.size(),n = mt[0].size();
        
        for(ll i=0; i<m; i++){
            ll l=0,r=n-1;
            while(l<=r){
                ll mid = l+ (r-l)/2;
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
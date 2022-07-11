class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        vector<int> dp(m);
        for(int j= 0; j<m;j++){
            dp[j] = tri[m-1][j];
        }
        for(int i= m-2; i>=0; i--){
            vector<int> temp(m);
            for(int j=i;j>=0; j--){
                int b = dp[j];
                int d = dp[j+1];
                temp[j] = min(b,d) + tri[i][j];
            }
            dp = temp;
        }
        return dp[0];
    }
};
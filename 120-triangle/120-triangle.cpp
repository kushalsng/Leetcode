class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        for(int j= 0; j<m;j++){
            dp[m-1][j] = tri[m-1][j];
        }
        for(int i= m-2; i>=0; i--){
            for(int j=i;j>=0; j--){
                
                int b = dp[i+1][j];
                int d = dp[i+1][j+1];
                dp[i][j] = min(b,d) + tri[i][j];
            }
        }
        // for(int i=0; i<m; i++){
        //     for(int j=0;j<m; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
        // return dp[m-1][n-1];
    }
};
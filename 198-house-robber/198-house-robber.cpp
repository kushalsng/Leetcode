class Solution {
public:
    int rob(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> dp(n+1);
        dp[0] = nums[0];
        long long ans = nums[0];
        for(int i=1; i<n; i++){
            int a = nums[i], b = dp[i-1];
            if(i>1)a += dp[i-2];
            dp[i] = max(a,b);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
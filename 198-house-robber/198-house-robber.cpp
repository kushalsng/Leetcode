class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // if(n<=2)return *max_element(nums.begin(),nums.end());
        vector<long long> dp(n+1);
        
        int i=0;
        long long ans=LONG_LONG_MIN;
        while(i<n){
            if(i<2)dp[i] = nums[i];
            else if(i>2) dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
            else dp[i] = nums[i] + dp[i-2];
            ans = max(dp[i],ans);
            i++;
        }
        return ans;
    }
};
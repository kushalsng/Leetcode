class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp.back() = true;
        int dist = 1;
        for(int j = n-2; j>=0; j--){
            if(nums[j] >= dist)dp[j] = true, dist = 1;
            else dp[j] = false, dist++;
        }
        // for(auto x: dp)cout<<x<<" ";
        return dp[0];
    }
};
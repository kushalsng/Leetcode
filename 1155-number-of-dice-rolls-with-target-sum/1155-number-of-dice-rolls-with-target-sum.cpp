class Solution {
public:
    int solve(int ind,int n,int k,int target,vector<vector<int>> &dp,int mod){
        if(ind==n){
            if(target==0)return 1;
            return 0;
        }
        if(target<0)return 0;
        int val =0;
        if(dp[ind][target] != -1)return dp[ind][target];
        for(int i=1;i<=k;i++){
            target -= i;
            val = ((long long)val + (long long)solve(ind+1,n,k,target,dp,mod))%mod;
            target += i;
        }
        return dp[ind][target] = val;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
        return solve(0,n,k,target,dp,mod);
    }
};
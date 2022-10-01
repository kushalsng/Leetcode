class Solution {
public:
    int dp[101]={};
    int solve(int ind,string s){
        if(ind == s.size())return 1;
        if(dp[ind]!=0)return dp[ind];
        int ans=0;
        if(s[ind] != '0')ans += solve(ind+1,s);
        if(ind+1<s.size() and (s[ind] == '1' || s[ind] == '2' and s[ind+1] <= '6'))ans += solve(ind+2,s);
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        return solve(0,s);
    }
};
class Solution {
public:
    void solve(vector<int>& v, vector<vector<int>> &ans,vector<int> &vis, vector<int> nums){
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                //take
                vis[i] = 1;
                v.push_back(nums[i]);
                solve(v,ans,vis,nums);
                //not take
                v.pop_back();
                vis[i] =0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v, vis(nums.size());
        solve(v,ans,vis,nums);
        return ans;
    }
};
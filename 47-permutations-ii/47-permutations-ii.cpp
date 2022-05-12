class Solution {
public:
    void solve(int ind, vector<int> nums,set<vector<int>> &us){
        if(ind == nums.size()){
            us.insert(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            if(ind != i && nums[ind] == nums[i]) continue;
            swap(nums[ind], nums[i]);
            solve(ind+1,nums,us);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> us;
        solve(0,nums, us);
        for(auto it=us.begin(); it != us.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};
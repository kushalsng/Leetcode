class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        set<int>s;
        int n = nums.size();
        map<int,int> mp;
        vector<vector<int>> ans(2);
        for(int i=0; i<n; i++){
            s.insert(nums[i][0]);
            s.insert(nums[i][1]);
            mp[nums[i][1]]++;
        }
        for(auto it = s.begin(); it != s.end(); it++){
            if(mp.find(*it) == mp.end())ans[0].push_back(*it);
            else if(mp[*it] == 1)ans[1].push_back(*it);
        }
        return ans;
    }
};
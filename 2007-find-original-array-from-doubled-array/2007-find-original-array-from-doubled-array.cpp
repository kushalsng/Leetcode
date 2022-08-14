class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(auto x: nums){
            mp[x]++;
        }
        for(int i=n-1; i>=0; i--){
            if(mp.size() && nums[i]%2 ==0 && mp.find(nums[i]) != mp.end() && mp.find(nums[i]/2) != mp.end()){
                ans.push_back(nums[i]/2);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)mp.erase(nums[i]);
                mp[nums[i]/2]--;
                if(mp[nums[i]/2] == 0)mp.erase(nums[i]/2);
            }
            // cout<<mp.size()<<" ";
        }
        if(mp.size() == 0)return ans;
        else{
            ans.clear();
            return ans;
        }
    }
};
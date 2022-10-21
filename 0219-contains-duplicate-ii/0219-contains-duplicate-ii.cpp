class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0)return false;
        int n = nums.size();
        unordered_set<int> us;
        for(int i=0;i<min(k,n);i++){
            if(us.find(nums[i]) != us.end())return true;
            else us.insert(nums[i]);
        }
        if(k<nums.size()){
            for(int i=0;i<nums.size()-k;i++){
                if(us.find(nums[i+k]) != us.end())return true;
                else {
                    us.erase(nums[i]);
                    us.insert(nums[i+k]);
                }
            }
        }else{
            return nums.size() != us.size();
        }
        return false;
    }
    
};
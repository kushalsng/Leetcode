class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int dup =0, numsx = 0, ogx = 0;
        
        for(int i =0; i< nums.size(); i++){
            numsx ^= nums[i];
            ogx ^= i+1;
            
            if(i < nums.size() - 1){
                if(nums[i] == nums[i+1]) dup = nums[i];
            }
        }
        
        vector<int> v{dup, (dup ^ (numsx ^ ogx))};
        return v;
    }
};
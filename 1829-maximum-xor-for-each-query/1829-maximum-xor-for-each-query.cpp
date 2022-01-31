class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxnum = (1<<maximumBit) -1;
        vector<int> v(nums.size());
        int n = nums.size();
        int xr = 0;
        for(int j: nums) xr ^= j;
        for(int i=0; i<n; i++){
            v[i] = xr ^ maxnum;
            xr ^= nums.back();
            nums.pop_back();
        }
        return v;
    }
};
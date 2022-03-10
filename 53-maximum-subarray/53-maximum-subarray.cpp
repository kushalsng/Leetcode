class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long mx=0, mxall = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            mx = max<long long>(mx+ nums[i], nums[i]);
            mxall = max(mxall, mx);
                
        }
        return mxall;
    }
};
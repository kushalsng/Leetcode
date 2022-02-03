class Solution {
public:
    typedef long long ll;
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        if(nums.size() < (2*k + 1))return ans;
        ll sum=0;
        for(int i=0; i< 2*k + 1; i++){
            sum += nums[i];
        }
        
        ans[k] = sum / (2*k +1);
        for(ll r=2*k + 1, l=0; r<nums.size();r++,l++){
            sum += (nums[r] - nums[l]);
            ans[r - k] = sum / (2*k + 1);
        }
        return ans;
    }
};
class Solution {
public:
    typedef long long ll;
    int minSubArrayLen(int target, vector<int>& nums) {
        ll i=0, j=0, mn = INT_MAX, sum =0;
        for(auto i: nums) sum += i;
        
        if(sum < target) return 0;
        if(sum == target) return nums.size();
        sum =0;
        while(j< nums.size()){
            sum += nums[j];
            if(sum < target) j++;
            else if(sum == target){
                mn = min<ll>(mn, j-i+1);
                j++;
            }else if(sum > target){
                while(sum > target){
                    mn = min<ll>(mn, j-i+1);
                    sum -= nums[i];
                    i++;
                }
                if(sum == target) mn = min<ll>(mn, j-i+1);
                j++;
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
};
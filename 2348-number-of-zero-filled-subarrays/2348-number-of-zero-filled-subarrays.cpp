class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0, n = nums.size();
        int i=0,j=0;
        while(j<n){
            if(nums[j]!=0){
                int val = j-i;
                ans += (long long)((long long)val*((long long)val+1))/2;
                j++;
                i=j;
            }else j++;
            
        }
        int val = j-i;
        ans += (long long)((long long)val*((long long)val+1))/2;
        return ans;
    }
};
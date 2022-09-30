class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i=0,j=2,ans=0,n=nums.size();
        if(n<3)return 0;
        int diff = nums[1]-nums[0];
        while(j<n){
            if(nums[j] - nums[j-1] != diff){
                diff = nums[j] - nums[j-1];
                int val = j-i;
                if(val>=3)ans += ((val*(val+1))/2) - (2*val - 1);
                i=j-1;
            }
            j++;
        }
        int val = j-i;
        if(val>=3)ans += ((val*(val+1))/2) - (2*val - 1);
        return ans;
    }
};
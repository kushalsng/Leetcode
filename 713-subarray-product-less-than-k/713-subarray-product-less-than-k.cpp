class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0,ans=0, pro=1;
        while(j<nums.size()){
            pro *= nums[j];
            if(pro < k){
                ans += j-i+1;
                j++;
            }else{
                while(pro>= k && i<=j){
                    pro /= nums[i];
                    i++;
                }
                if(pro<k) ans += j-i+1;
                j++;
            }
        }
        return ans;
    }
};
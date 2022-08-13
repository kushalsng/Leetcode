class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0, n = nums.size();
        for(int i=0; i<n-2; i++){
            int j=i+1,  k=n-1;
                while(j<k){
                    if(nums[j] - nums[i] == diff){
                        // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<", ";
                        if(nums[k] - nums[j]== diff)ans++, k--,j++;
                        else if(nums[k] - nums[j] > diff)k--;
                        else j++;
                    }else j++;
                }
                j=i+1, k=n-1;
            }
        
        return ans;
    }
};
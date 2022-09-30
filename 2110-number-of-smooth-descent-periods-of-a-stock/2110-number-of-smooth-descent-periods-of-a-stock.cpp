class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        int n = nums.size();
        long long ans = n;
        int i=0,j=1;
        while(j<n){
            if(nums[j] == nums[j-1]-1)j++;
            else{
                int sz  = j-i;
                ans += (long long)((long long)sz*((long long)sz-1))/2;
                i=j;
                j++;
            }
        }
        int sz  = j-i;
        ans += (long long)((long long)sz*((long long)sz-1))/2;
        return ans;
    }
};
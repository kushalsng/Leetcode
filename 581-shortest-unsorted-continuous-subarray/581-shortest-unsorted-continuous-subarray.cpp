class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() ==1)return 0;
        // cout<<nums.size()<<endl;
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(i<nums.size()-1 && nums[i]<=nums[i+1])++i;
            if(j>0 && nums[j]>=nums[j-1])--j;
            if(j>0 && i<nums.size()-1 && nums[j]<nums[j-1] && nums[i]>nums[i+1])break;
        }
        cout<<i<<" "<<j<<endl;
        if(i>j)return 0;
        int mn =INT_MAX, mx = INT_MIN;
        for(int k=i; k<=j; k++){
            mn = min(nums[k], mn);
            mx = max(nums[k], mx);
        }
        cout<<i<<" "<<j<<endl;
        while(i>0 && nums[i-1]>mn) i--;
        while(j<nums.size()-1 && nums[j+1]<mx)j++;
        cout<<i<<" "<<j<<endl;
        return j-i+1;
    }
};
class Solution {
public:
    int bs(vector<int>& nums, int l, int r, int target){
        int mid = (l+r)/2;
        int index=0;
        if(nums[mid] == target) return mid;
        
        if(abs(l-r) <= 1){
            if(nums[l] != target && nums[r] != target){
                if(nums[l]>target) return l;
                else if(nums[r]>target) return r;
            }
        }
        
        if(nums[mid]<target)    
            index = bs(nums, mid+1, r, target);
        else
            index = bs(nums, l, mid-1, target);
        // cout<<index<<endl;
        return index;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r= nums.size()-1;
        if(nums[nums.size()-1] < target) return nums.size();
        return bs(nums, l, r, target);
    }
};
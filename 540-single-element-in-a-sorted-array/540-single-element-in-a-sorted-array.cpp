class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l=0, r= nums.size() -1;
        if(nums[l] != nums[l+1]) return nums[l];
        if(nums[r] != nums[r-1]) return nums[r];

        while(l<=r){
            int mid = l + (r - l)/2;
            if(nums[mid] != nums[mid +1] && nums[mid] != nums[mid-1])
                return nums[mid];
            else if(nums[mid] == nums[mid-1]){
                if((mid - 1 - l) %2 !=0)
                    r= mid -2;
                else
                    l = mid +1;
            }else {
                if((r - 1 - mid) % 2 != 0)
                    l = mid + 2;
                else 
                    r = mid - 1;
            }
        }
        return -1;
    }
};
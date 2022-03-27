class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l =0, r= nums.size() -1;
        int ans=-1;
        if(nums.size() == 1) return 0;
        // if(nums[0]>nums[1]) return 0;
        // if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            cout<<mid<<" ";
            if(mid >0 && mid< nums.size()-1){
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    ans = mid;
                    break;
                }
                else if(nums[mid] < nums[mid-1]) r= mid-1;
                else if(nums[mid] < nums[mid+1]) l = mid+1;
            }else if(mid ==0){
                if(nums[mid]> nums[mid+1]){
                    ans = mid; break;
                }
                else l = mid+1;
            }else if(mid == nums.size()-1){
                if(nums[mid]> nums[mid-1]){
                    ans = mid;
                    break;
                }
                else r=mid-1;
            }
        }
        return ans;
    }
};
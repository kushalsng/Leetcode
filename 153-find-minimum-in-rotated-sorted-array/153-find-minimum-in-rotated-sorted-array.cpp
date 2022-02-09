class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=-6000;
        int N = nums.size();
        int l=0,r=N-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int prev = (mid -1 + N) % N;
            int next = (mid +1) % N;
            if(nums[mid] <= nums[prev] && nums[mid]<= nums[next]){
                ans = nums[mid]; break;
            }
            else if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size(), i=1;
        while(i<N){
            int left = i;
            if(nums[i] == nums[i-1]){
                left++;
                while(i<N && nums[i] == nums[i - 1]) i++;

                nums.erase(nums.begin() + left, nums.begin() + i);
                N -= i - left;
                i = left;
                // i == N ? nums.erase(nums.begin() + left, nums.end())
                //     : nums.erase(nums.begin() + left, nums.begin() + i);
//                 if(left < N){
//                     // i == N ? nums.erase(nums.begin() + left, nums.end())
//                     // : nums.erase(nums.begin() + left, nums.begin() + i);
                    
//                 }
            } else i++;
        }
        // return nums.size();
        return N;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        // vector<int> ans;
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum == k)return {i+1,j+1};
            else if(sum> k)j--;
            else i++;
        }
        return {};
    }
};
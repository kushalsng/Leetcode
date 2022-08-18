class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=INT_MIN,cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(num == nums[i])cnt++;
            else if(cnt==0)num = nums[i];
            else cnt--;
        }
        return num;
    }
};
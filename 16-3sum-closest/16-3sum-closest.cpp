class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int a=1e9,b=-1e9;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0; i<n-2; i++){
            int j=i+1,k=n-1;
            while(j<k){
                // int val = target - (nums[i]+nums[j]+nums[k]);
                int sum = (nums[i]+nums[j]+nums[k]);
                if(sum == target) return sum;
                else if(sum > target){
                    a = min(a, sum);
                    k--;
                }else{
                    b = max(b, sum);
                    j++;
                }
                
            }
        }
        return abs(target - a) > abs(target - b) ? b: a;
    }
};
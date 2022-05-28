class Solution {
public:
    int rob(vector<int>& nums) {
        long long n = nums.size();
        long long ans = nums[0], p1 = nums[0], p2=0;
        for(int i=1; i<n; i++){
            long long curr = nums[i] + p2;
            ans = max(p1, curr);
            p2 = p1;
            p1 = max(p1,curr);
        }
        return ans;
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        long long n = nums.size();
        if(n==1)return nums[0];
        long long ans1 =nums[0], p1 = nums[0], p2=0;
        
        for(int i=1; i<n-1; i++){
            long long curr = nums[i] + p2;
            ans1 = max(p1, curr);
            p2 = p1;
            p1 = max(p1,curr);
        }
        long long ans2=0;
        if(n>1){
            ans2 = nums[1];
            p1 = nums[1], p2 =0;
            for(int i=2; i<n; i++){
                long long curr = nums[i] + p2;
                ans2 = max(p1, curr);
                p2 = p1;
                p1 = max(p1,curr);
            }
        }
        return max(ans1,ans2);
    }
};
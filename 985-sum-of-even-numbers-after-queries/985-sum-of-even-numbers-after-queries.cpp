class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0,n =nums.size();
        vector<int> ans(n);
        for(auto x: nums) if(x%2==0)sum += x;
        for(int i=0; i<n; i++){
            if(nums[queries[i][1]] %2==0){
                sum -= nums[queries[i][1]];
            }
            nums[queries[i][1]] += queries[i][0];
            if(nums[queries[i][1]]%2==0)sum += nums[queries[i][1]];
            ans[i] = sum;
        }
        return ans;
    }
};
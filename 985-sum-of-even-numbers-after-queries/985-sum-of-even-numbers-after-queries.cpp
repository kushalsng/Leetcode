class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0,n =nums.size();
        vector<int> ans(n);
        for(auto x: nums) if(x%2==0)sum += x;
        for(int i=0; i<n; i++){
            int tans=nums[queries[i][1]];
            if(tans %2==0){
                sum -= tans;
            }
            tans += queries[i][0];
            nums[queries[i][1]] = tans;
            if(tans%2==0)sum += tans;
            ans[i] = sum;
            // sum = save;
        }
        return ans;
    }
};
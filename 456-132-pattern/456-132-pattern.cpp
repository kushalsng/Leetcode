class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int sm = INT_MIN;
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            if(nums[i]<sm) return true;
            while(!s.empty() && s.top()<nums[i]){
                sm = max(sm, s.top());
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
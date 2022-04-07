class Solution {
public:
    typedef long long ll;
    int minElements(vector<int>& nums, int limit, int goal) {
        ll sum=0;
        for(auto x: nums) sum += x;
        ll  diff = abs(sum-goal);
        ll ans = diff/limit;
        if(diff%limit)++ans;
        return ans;
    }
};
class Solution {
public:
    int fourSumCount(vector<int>& a1, vector<int>& a2, vector<int>& a3, vector<int>& a4) {
        map<int,int> mp;
        int ans=0;
        for(auto k: a3)
            for(auto l: a4)
                mp[k+l]++;
        for(auto i: a1)
            for(auto j: a2)
                ans += mp[-(i+j)];
        return ans;
    }
};
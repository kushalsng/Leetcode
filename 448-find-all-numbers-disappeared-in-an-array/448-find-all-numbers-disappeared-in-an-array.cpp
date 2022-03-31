class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        for(auto x: nums){
            s.insert(x);
        }
        vector<int> ans;
        for(auto i=1; i<=nums.size();i++){
            if(s.find(i) == s.end())ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(auto x: nums){
            if(us.find(x) == us.end()) us.insert(x);
            else return true;
        }
        return false;
    }
};
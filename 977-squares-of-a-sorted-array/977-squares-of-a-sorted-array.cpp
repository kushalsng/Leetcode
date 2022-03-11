class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        map<int,int> mp;
        for(auto x: nums){
            mp[abs(x)]++;
        }
        auto it = mp.begin();
        for(int i=0;i<nums.size();){
            while(it != mp.end()){
                while(it->second--){
                    nums[i++] = it->first * it->first;
                }
                it++;
            }
        }
        return nums;
    }
};
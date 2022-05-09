class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto x: nums)mp[x]++;
        if(k==0){
            for(auto it= mp.begin(); it != mp.end(); it++){
                if(it->second > 1)ans++;
            }
        }
        else{
            for(auto x: nums){
                if(mp.find(x) != mp.end()){
                    if(mp.find(x+k) != mp.end())ans++;
                    if(mp.find(x-k) != mp.end())ans++;
                    mp.erase(x);
                }
            }
        }
        return ans;
    }
};
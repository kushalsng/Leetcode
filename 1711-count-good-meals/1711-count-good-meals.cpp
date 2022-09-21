class Solution {
public:
    int countPairs(vector<int>& arr) {
        int ans=0, n=arr.size(),mx=0;
        int mod = 1e9+7;
        map<long ,long>mp;
        for(auto x: arr)mp[x]++, mx = max(mx,x);
        for(auto it =mp.begin(); it!= mp.end(); it++){
            // cout<<ans<<" ";
            for(int j = 0; j<=21; j++){
                
                int val = (1<<j);
                val -= it->first;
                if(val == it->first){
                    ans = (ans + (it->second * (it->second-1))/2)%mod;
                }
                else if(mp.find(val) != mp.end()){
                     ans = (ans + (it->second* mp[val]))%mod;
                }
            }
            it->second = 0;
        }
        return ans;
    }
};
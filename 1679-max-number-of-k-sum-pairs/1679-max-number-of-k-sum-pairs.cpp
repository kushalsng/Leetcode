class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        long long ans=0;
        map<int,int> mp;
        for(auto x: nums)mp[x]++;
        auto i=mp.begin();
        auto j = mp.rbegin();
        while(j!= mp.rend() && j->first >=k)j++;
        while(j !=mp.rend() && i!=mp.end() && i->first<= j->first){
            int sum = i->first + j->first;
            if(sum == k){
                if(i->first == j->first)ans+= i->second/2;
                else ans+= min(i->second, j->second);
                i++,j++;
            }else if(sum > k){
                j++;
            }else i++;
        }
        // while(i<=j){
        //     if(mp.find(i) != mp.end() && mp.find(j) != mp.end()){
        //         if(i==j){
        //             ans+= mp[i]/2;
        //             mp.erase(i);
        //         }else{
        //             ans += min(mp[i],mp[j]);
        //             mp.erase(i); mp.erase(j);
        //         }
        //     }
        //     i++, j--;
        // }
        return ans;
    }
};
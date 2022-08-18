class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto x: arr)mp[x]++;
        vector<int>pq;
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push_back(it->second);
        }
        sort(pq.begin(),pq.end());
        int m = n;
        int ans=0;
        while(m>n/2){
            m -= pq.back();
            pq.pop_back();
            ans++;
        }
        return ans;
    }
};
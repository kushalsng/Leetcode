class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto x: arr)mp[x]++;
        priority_queue<int> pq;
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push(it->second);
        }
        int m = n;
        int ans=0;
        while(m>n/2){
            m -= pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
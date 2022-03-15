class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for(auto c: s) mp[c]++;
        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->second, it->first});
        }
        string ans = "";
        while(!pq.empty()){
            int i=0;
            while(i< pq.top().first) {
                ans += pq.top().second;
                i++;
            }
            pq.pop();
        }
        return ans;
    }
};
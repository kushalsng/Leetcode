class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        vector<pair<char,int>> dist;
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]] == 0) dist.push_back({s[i], i});
            mp[s[i]]++;
        }
        for(int i=0; i<dist.size(); i++){
            if(mp[dist[i].first] == 1) return dist[i].second;
        }
        return -1;
    }
};
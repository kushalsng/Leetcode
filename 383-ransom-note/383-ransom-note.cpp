class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mp;
        for(auto c: m)mp[c]++;
        for(auto c: r){
            if(mp[c] == 0) return false;
            mp[c]--;
        }
        // for(auto it = mp.begin(); it != mp.end(); it++){
        //     if(it->second < 0) return false;
        // }
        return true;
    }
};
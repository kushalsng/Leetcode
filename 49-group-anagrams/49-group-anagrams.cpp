class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c: s)mp[c]++;
        for(auto c: t){
            if(mp[c] == 0) return false;
            mp[c]--;
        }
        for(auto it = mp.begin();it != mp.end(); it++){
            if(it->second != 0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        
        for(int i=0; i<strs.size(); i++){
            string save = strs[i];
            sort(strs[i].begin(),strs[i].end());
            cout<<strs[i]<<" "<<save<<", ";
            mp[strs[i]].push_back(save);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
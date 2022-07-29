class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        for(auto s: words){
            unordered_map<char, char> mp;
            unordered_set<char> us;
            bool isPerm = true;
            for(int i=0; i<s.size(); i++){
                if(mp.find(p[i]) == mp.end()){
                    if(us.find(s[i]) == us.end()){
                        mp[p[i]] = s[i];
                        us.insert(s[i]);
                    }else{
                        isPerm = false;
                        break;
                    }
                        
                }else if(mp[p[i]] != s[i]){
                    isPerm = false;
                    break;
                }
            }
            if(isPerm) ans.push_back(s);
        }
        return ans;
    }
};
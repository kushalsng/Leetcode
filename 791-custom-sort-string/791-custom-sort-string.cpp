class Solution {
public:
    string customSortString(string s, string t) {
        map<char,int> tt;
        // for(auto x: s)ss.insert(x);
        for(auto x: t)tt[x]++;
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(tt.count(s[i])){
                while(tt[s[i]]--)ans += s[i];
                tt.erase(s[i]);
            }
        }
        for(auto it = tt.begin(); it != tt.end(); it++){
            while(it->second--)ans += it->first;
        }
        return ans;
    }
};
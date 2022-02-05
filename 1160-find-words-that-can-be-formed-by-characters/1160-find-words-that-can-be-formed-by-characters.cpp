class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> forch(26,0);
        int ans =0;
        for(auto i: chars)forch[i - 'a']++;
        
        for(int i=0; i<words.size(); i++){
            vector<int> forst(26,0);
            for(auto s: words[i]) forst[s - 'a']++;
            bool isValid = true;
            for(int j=0; j<26; j++){
                if(forst[j] > forch[j] && isValid) isValid = false;
            }
            if(isValid) ans += words[i].size();
        }
        return ans;
    }
};
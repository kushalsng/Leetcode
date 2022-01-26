class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> prev(26,0), curr(26,0);
        char res;
        for(int i =0; i<s.size(); i++){
            prev[s[i] - 97]++;
        }
        for(int i =0; i<t.size(); i++){
            curr[t[i] - 97]++;
        }
        for(int i=0; i<26; i++){
            if(prev[i] != curr[i]) res = i+97;
        }
        return res;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        int fors=0, fort = 0;
        for(int i =0 ;i< s.size();i++) fors ^= s[i];
        for(int i =0 ;i< t.size();i++) fort ^= t[i];
        
        return fors ^ fort;
    }
};
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        // partans += s[s.size()-1] - 'A' + 1;
        for(int i=0; i<s.size()-1;i++){
            ans += s[i] - 'A' + 1;
            ans *= 26;
        }
        
        ans += s[s.size()-1] - 'A' + 1;
        return ans;
    }
};
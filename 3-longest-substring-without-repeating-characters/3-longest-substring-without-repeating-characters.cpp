class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,i=0, j=0;
        unordered_map<char,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]] == 1){
                ans = max(ans, j-i+1);
                j++;
            }else{
                while(mp[s[j]] > 1){
                    --mp[s[i]];
                    ++i;
                }
                if(mp[s[j]] == 1) ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};
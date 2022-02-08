class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> fors(26,0);
        vector<int> fort(26,0);

        for(int i=0;i<s.size();i++){
            fors[s[i] - 'a']++;
            fort[t[i] - 'a']++;
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            if(fort[i] < fors[i]) ans += abs(fors[i] - fort[i]);
        }
        return ans;
    }
};
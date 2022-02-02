class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size()< p.size()) return ans;
        vector<int> alphap(26,0);
        vector<int> alphas(26,0);
        
        for(int i=0; i<p.size(); i++){
            alphap[p[i] - 'a']++;
        }
        int l=0, r=p.size();
        while(r<=s.size()){
            for(int j=l;j<r; j++) alphas[s[j] - 'a']++;
            bool isAnagram = true;
            for(int i=0; i<26; i++){
                if(alphap[i] != alphas[i]){
                    isAnagram = false; break;
                }
            }
            if(isAnagram) ans.push_back(l);
            fill(alphas.begin(), alphas.end(), 0);
            l++, r++;
        }
        return ans;
    }
};
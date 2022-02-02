class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> chars1(26,0);
        vector<int> chars2(26,0);
        for(int i=0; i<s1.size(); i++){
            chars1[s1[i] - 'a']++;
        }
        int l=0, r=s1.size();
        while(r<=s2.size()){
            for(int j=l;j<r; j++) chars2[s2[j] - 'a']++;
            bool isPermute = true;
            for(int i=0; i<26; i++){
                if(chars1[i] != chars2[i]){
                    isPermute = false;
                    break;
                }
            }
            if(isPermute) return true;
            fill(chars2.begin(), chars2.end(), 0);
            l++;r++;
        }
        return false;
    }
};
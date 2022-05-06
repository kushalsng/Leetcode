class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> cnt(s.size());
        for(int i=0; i<s.size(); i++){
            if(i==0 || s[i]!=s[i-1]) cnt[i] = 1;
            else{
                cnt[i] = cnt[i-1]+1;
                if(cnt[i] == k){
                    s.erase(i-k+1, k);
                    i -= k;
                }
            }
        }
        return s;
    }
};
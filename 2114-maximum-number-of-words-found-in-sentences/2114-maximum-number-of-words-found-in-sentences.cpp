class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(auto sen: sentences){
            int cnt=1;
            for(auto c: sen) if(c== ' ') cnt++;
            ans = max(cnt, ans);
        }
        return ans;
    }
};
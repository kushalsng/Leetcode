class Solution {
public:
    int bagOfTokensScore(vector<int>& toks, int power) {
        int n = toks.size();
        sort(toks.begin(),toks.end());
        int ans =0, mx = 0;
        int i=0,j=n-1;
        if(i == j){
            if(power >= toks[i])return 1;
            return 0;
        }
        while(i<j){
            while(power >= toks[i]){
                ans++;
                power -= toks[i];
                i++;
            }
            mx = max(mx,ans);
            if(i<j){
                if(ans == 0)return 0;
                power += toks[j];
                ans--;
                j--;
            }
            mx = max(mx,ans);
        }
        return mx;
    }
};
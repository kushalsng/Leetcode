class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mxP=0, mnP=INT_MAX;
        for(int i=0; i< p.size(); i++){
            mnP =min(mnP, p[i]);
            mxP = max(mxP, abs(p[i] - mnP));
        }
        return mxP;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& nint) {
        vector<vector<int>> ans;
        int n=ints.size();
        int i=0;
        while(i<n){
            if(ints[i][1] >= nint[0] && nint[1] >= ints[i][0]){
                ans.push_back({min(ints[i][0], nint[0]), max(ints[i][1], nint[1])});
                break;
            } else if((ans.empty() || ans.back()[1] < nint[0]) && ints[i][0] > nint[1]){
                ans.push_back(nint);
                break;
            }
            else{
                ans.push_back(ints[i]);
            }
            i++;
        }
        while(i<n){
            if(ans.back()[1] < ints[i][0])ans.push_back(ints[i]);
            else{
                ans.back()[1] = max(ans.back()[1],ints[i][1]);
            }
            i++;
        }
        if(ans.empty() || ans.back()[1]< nint[0])ans.push_back(nint);
        return ans;
    }
};
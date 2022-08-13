class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        vector<vector<int>> ans;
        int n = ints.size();
        sort(ints.begin(),ints.end());
        
        for(int i=0; i<n; i++){
            if(ans.empty() || ans.back()[1] < ints[i][0]){
                ans.push_back({ints[i][0], ints[i][1]});
            }else{
                ans.back()[1] = max(ans.back()[1], ints[i][1]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    void fun(vector<int>& candidates, int in, vector<int>& v, int target, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(v);
        }
        
        for(int i = in; i<candidates.size(); i++){
            if(i>in && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            v.push_back(candidates[i]);
            fun(candidates, i+1, v, target - candidates[i], ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        
        fun(candidates, 0, v, target, ans);
        return ans;
    }
};
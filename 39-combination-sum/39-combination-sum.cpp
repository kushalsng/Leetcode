class Solution {
public:
    void find(int i, vector<int> arr, vector<int>& v, vector<vector<int>>& ans, int target){
        if(i>=arr.size()){
            if(target == 0) ans.push_back(v);
            return;
        }
        
        if(arr[i]<= target){
            v.push_back(arr[i]);
            find(i, arr, v, ans, target - arr[i]);
            v.pop_back();
        }
        find(i+1, arr, v, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        find(0, candidates, v, ans, target);
        return ans;
    }
};
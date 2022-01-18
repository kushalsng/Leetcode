class Solution {
public:
    void findSubset(vector<int> a, int index, vector<int> &v, vector<vector<int>> &ans){
        if(index>=a.size()){
            vector<vector<int>>::iterator it;
            it = find(ans.begin(), ans.end(), v);
            if(it == ans.end()) ans.push_back(v);
            return;
        }
        
        v.push_back(a[index]);
        findSubset(a, index+1, v, ans);
        v.pop_back();
        findSubset(a, index+1, v, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        findSubset(nums, 0, v, ans);
        return ans;
    }
};
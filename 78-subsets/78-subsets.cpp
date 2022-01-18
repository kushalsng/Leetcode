class Solution {
public:
    void findSubset(vector<int> a, vector<int> &v, vector<vector<int>> &ans, int index){
        if(index>=a.size()){
            ans.push_back(v);
            return;
        }
        
        v.push_back(a[index]);
        findSubset(a,v,ans,index+1);
        v.pop_back();
        findSubset(a,v,ans, index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        findSubset(nums, v, ans, 0);
        return ans;
    }
};
class Solution {
public:
    void combo(int ind, int n, int k, vector<int> &v, vector<vector<int>> &ans){
        if(v.size() == k) {
            ans.push_back(v);
            return;
        }
        
        for(int i= ind; i<=n; i++){
            if(k > (n - i + 1) + v.size()) break;
            v.push_back(i);
            combo(i+1, n, k, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> ans;
        combo(1, n, k, v, ans);
        return ans;
    }
};
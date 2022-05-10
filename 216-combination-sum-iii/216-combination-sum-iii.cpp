class Solution {
public:
    void solve(int x, int sum, int k, int n, vector<vector<int>> &ans, vector<int> &v){
        if(x == 10 || v.size() == k){
            if(v.size() == k){
                if(sum == n)ans.push_back(v);
            }
            return;
        }
        v.push_back(x);
        sum += x;
        solve(x+1, sum, k, n, ans, v);
        v.pop_back();
        sum -= x;
        solve(x+1, sum, k, n, ans, v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1, 0, k, n, ans, v);
        return ans;
    }
};
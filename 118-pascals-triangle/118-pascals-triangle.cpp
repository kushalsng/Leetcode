class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1; i<num;i++){
            vector<int> v;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) v.push_back(1);
                else v.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
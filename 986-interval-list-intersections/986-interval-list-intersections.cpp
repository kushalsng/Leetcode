class Solution {
public:
    // vector<int> solve(vector<vector<int>>& f, vector<vector<int>>& s, int i, int j, int x, int y){
    //     vector<int> v;
    // }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int m = f.size(), n= s.size();
        int i=0,j=0,x=0,y=0;
        while(i<m && j<n){
            vector<int> tans;
            if(x==0 && y==0){
                if(s[j][y] > f[i][x+1]) i++;
                else if(s[j][y+1] < f[i][x]) j++;
                else{
                    tans.push_back(max(f[i][x++],s[j][y++]));
                    tans.push_back(min(f[i][x],s[j][y]));
                    ans.push_back(tans);
                    if(f[i][x] == s[j][y]){
                        i++,j++;
                    }else if(f[i][x]<s[j][y]){
                        i++;
                    }else j++;
                    y=0,x=0;
                }
            }
        }
        return ans;
    }
};
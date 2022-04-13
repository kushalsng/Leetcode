class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mt) {
        vector<int> ans;
        int m = mt.size(),n= mt[0].size();
        int i=0,j=0, il=m-1, jl= n-1;
        pair<int, int> p1 = {m-1, n-1}, p2 = {1, 0};
        // int cnt = 0;
        while(ans.size() < m*n){
            while(j != jl){
                if(j<jl) ans.push_back(mt[i][j++]);
                else ans.push_back(mt[i][j--]);
                if(ans.size() == m*n) break;
            }
            if(ans.size() == m*n) break;
            while(i != il){
                if(i<il) ans.push_back(mt[i++][j]);
                else ans.push_back(mt[i--][j]);
                if(ans.size() == m*n) break;
            }
            if(il == p1.first && jl == p1.second){
                il = p2.first, jl = p2.second;
                p1.first--,p1.second--;
            }else {
                il = p1.first, jl = p1.second;
                p2.first++,p2.second++;
            }
        }
        // ans.push_back(mt[il][jl]);
        return ans;
    }
};
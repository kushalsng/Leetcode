class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        int val=1, i=0,j=0,il=n-1,jl=n-1;
        pair<int,int>p1 = {n-1,n-1}, p2 = {1,0};
        while(val<n*n){
            while(j != jl){
                j<jl ? v[i][j++] = val++ : v[i][j--] = val++;
            }
            if(val == n*n)break;
            while(i != il){
                i<il ? v[i++][j] = val++ : v[i--][j] = val++;
            }
            if(il == p1.first && jl == p1.second){
                il=p2.first, jl = p2.second;
                p1.first--,p1.second--;
            }else{
                il = p1.first, jl = p1.second;
                p2.first++,p2.second++;
            }
        }
        if(n%2) v[p1.first][p1.second] = val;
            else v[p2.first][p2.second] = val;
        
        return v;
    }
};
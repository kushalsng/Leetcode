class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int m = a.size(), n= a[0].size();
        vector<pair<int,pair<int,int>>> vpp;
        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                int sum=0;
                if(i-1>=0){
                    if(j-1>=0) sum+= a[i-1][j-1];
                    sum+=a[i-1][j];
                    if(j+1<n) sum += a[i-1][j+1];
                }
                if(i+1<m){
                    if(j-1>=0) sum+= a[i+1][j-1];
                    sum += a[i+1][j];
                    if(j+1<n)sum += a[i+1][j+1];
                }
                if(j-1>=0) sum += a[i][j-1];
                if(j+1<n) sum += a[i][j+1];
                
                if(a[i][j] == 1){
                    if(sum <2 || sum>3)vpp.push_back({0,{i,j}});
                }
                else{
                    if(sum == 3)vpp.push_back({1,{i,j}});
                }
            }
        }
        for(auto p: vpp){
            a[p.second.first][p.second.second] = p.first;
        }
    }
};
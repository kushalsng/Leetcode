class Solution {
    vector<int> dx{-1,0,1,0}, dy{0,-1,0,1};
    // int vis[301][301];
    int m,n;
public:
    bool isValid(int x, int y){
        return (x>=0 && x<m && y>=0 && y<n);
    }
    void dfs(int x, int y, vector<vector<int>>& land, pair<int,int> &mx){
        land[x][y] = 0;
        for(int i=0; i<4; i++){
            int a = x+dx[i], b= y+dy[i];
            if(isValid(a,b) && land[a][b] == 1){
                mx.first = max(mx.first,a);
                mx.second = max(mx.second,b);
                dfs(a,b,land,mx);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        m = land.size(), n = land[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j] == 1){
                    pair<int,int> mn{i,j} , mx{-1,-1};
                    mx.first = max(mx.first,i);
                    mx.second = max(mx.second,j);
                    dfs(i,j,land,mx);
                    ans.push_back({mn.first,mn.second,mx.first,mx.second});
                }
            }
        }
        return ans;
    }
};